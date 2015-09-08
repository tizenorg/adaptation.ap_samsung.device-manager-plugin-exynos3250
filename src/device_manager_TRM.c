/*
	Tizen Resource Manager
	yu.baek@samsung.com

*/
#include <string.h>
#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#include "device_manager_TRM.h"
#include "devman_define_node_path.h"
#include "device_manager_io.h"

#define DEVMGR_LOG
#if defined (DEVMGR_LOG)
#define LOG_TAG "DEVICE_PLUGIN"
#include <dlog/dlog.h>
#define devmgr_log(fmt, args...)	SLOGI(fmt, ##args)
#else
#define devmgr_log(fmt, args...)
#endif


#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/types.h>
#include <linux/un.h>

static pthread_t trm_server_thread;
static int socketfd_scenario_listen = -1;
#define TRM_SOCKET_FOR_OAL		"/dev/socket/oal"
static struct sockaddr_un addr;
void *TRM_scenario_thread(void *data)
{
	#define MAX_REV_BUF_LEN	64

	int ret;
	socklen_t len;
	int socketfd_connect = 0;
	char receive_buf[MAX_REV_BUF_LEN] = {0, };

	for (;;) {
		len = sizeof(struct sockaddr_un);
		socketfd_connect = accept(socketfd_scenario_listen, (struct sockaddr *) &addr, &len);
		if (socketfd_connect == -1) {
			devmgr_log("%s: accept failed", __func__);
			continue;
		}

		memset(receive_buf, 0, MAX_REV_BUF_LEN);
		ret = recv(socketfd_connect, receive_buf, MAX_REV_BUF_LEN, 0);
		if (ret <= 0) {
			devmgr_log("%s: recv failed", __func__);
			goto close_connect;
		}

close_connect:
		close(socketfd_connect);
	}

	return NULL;
}

int TRM_oal_socket_init()
{
	int ret = 0, running_step = 0;
	devmgr_log("TRM_socket_init");

	socketfd_scenario_listen = socket(PF_UNIX, SOCK_STREAM, 0);
	if (socketfd_scenario_listen < 0) {
		running_step = 1;
		goto error;
	}

	memset(&addr, 0, sizeof(struct sockaddr_un));
	snprintf(addr.sun_path, UNIX_PATH_MAX, TRM_SOCKET_FOR_OAL);
	addr.sun_family = AF_UNIX;

	ret = bind(socketfd_scenario_listen, (struct sockaddr *)&addr, sizeof(struct sockaddr_un));
	if (ret != 0) {
		running_step = 2;
		goto error;
	}

	chmod(addr.sun_path, 0660);
	ret = listen(socketfd_scenario_listen, 2);
	if (ret != 0) {
		running_step = 3;
		goto error;
	}

	return 0;

error:
	devmgr_log("%s running_step=%d ret=%d", __FUNCTION__, running_step, ret);
	if (socketfd_scenario_listen != -1) {
		close(socketfd_scenario_listen);
		socketfd_scenario_listen = -1;
	}
	return -1;
}


int TRM_demon_init()
{
	int ret = 0, running_step = 0;

	if (access(TRM_SOCKET_FOR_OAL, F_OK) == 0)
		goto success;

	devmgr_log("%s\n", __FUNCTION__);

	ret = TRM_oal_socket_init();
	if (ret < 0) {
		running_step = 1;
		goto fail;
	}

	ret = pthread_create(&trm_server_thread, NULL, TRM_scenario_thread, NULL);
	if (ret != 0) {
		running_step = 2;
		goto fail;
	}
	pthread_detach(trm_server_thread);
success:
	return 0;

fail :
	devmgr_log("%s running_step=%d ret=%d", __FUNCTION__, running_step, ret);
	return -1;


}


void TRM_send_socket(char *soket_path, char *write_buf)
{
	int socket_fd = 0;
	int ret = 0, running_step = 0;
	struct sockaddr_un addr;
	static int socket_exist = 0;

	if (access(soket_path, F_OK) == 0) {
		socket_exist = 1;
	} else {
		devmgr_log("%s do not exist\n", soket_path);
	}

	if (socket_exist == 0)
		goto fail;

	socket_fd = socket(AF_LOCAL, SOCK_STREAM, 0);
	if (socket_fd < 0) {
		running_step = 1;
		goto fail;
	}

	memset(&addr, 0, sizeof(addr));
	snprintf(addr.sun_path, UNIX_PATH_MAX, "%s", soket_path);
	addr.sun_family = AF_LOCAL;

	ret = connect(socket_fd, (struct sockaddr *) &addr ,sizeof(sa_family_t) + strlen(soket_path) );
	if (ret != 0) {
		running_step = 2;
		close(socket_fd);
		goto fail;
	}

	send(socket_fd, write_buf, strlen(write_buf), MSG_NOSIGNAL);

	close(socket_fd);

	return;

fail :
	return;

}



#define TRM_SOCKET_FOR_SCENARIO_INFO       "/dev/socket/scenario_info"

int Tizen_Resource_Manager(char *event_lock) {

	if ((strstr(event_lock, "GpuWakeup") == 0) && (strstr(event_lock, "BrowserScroll") == 0))
		devmgr_log("%s\n", event_lock);

	TRM_send_socket(TRM_SOCKET_FOR_SCENARIO_INFO, event_lock);

	return 0;

}


