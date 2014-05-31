/*
 * Copyright (c) 2012 Samsung Electronics Co., Ltd All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/


#ifndef	__DEVMAN_PLUGIN_INTF_H__
#define	__DEVMAN_PLUGIN_INTF_H__

enum {
	STATUS_OFFLINE	= 0,
	STATUS_ONLINE,
};

enum {
	STATUS_OFF	= 0,
	STATUS_ON,
};

enum {
	PATH_CP		= 0,
	PATH_AP,
};

enum {
	BATTERY_NOT_FULLY_CHARGED	= 0,
	BATTERY_FULLY_CHARGED,
};

enum {
	BATTERY_UNKNOWN		= 0,
	BATTERY_GOOD,
	BATTERY_OVERHEAT,
	BATTERY_DEAD,
	BATTERY_OVERVOLTAGE,
	BATTERY_UNSPECIFIED,
	BATTERY_COLD,
	BATTERY_HEALTH_MAX,
};

enum {
	POWER_STATE_SUSPEND	= 0,
	POWER_STATE_PRE_SUSPEND,
	POWER_STATE_POST_RESUME,
};

enum {
	POWER_UNLOCK	= 0,
	POWER_LOCK,
};

enum {
        LUX_DECREMENT,
        LUX_NOCHANGE,
        LUX_INCREMENT,
};

enum {
	WM_MODE_MIN = 0x00,
	WM_MODE_NORMAL = WM_MODE_MIN,
	WM_MODE_CONSERVATIVE,
	WM_MODE_MEDIUM,
	WM_MODE_AGGRESSIVE,
	WM_MODE_OUTDOOR,
	WM_MODE_MAX = WM_MODE_OUTDOOR
};

struct color_blind_info {
	bool power;
	unsigned short RrCr;
	unsigned short RgCg;
	unsigned short RbCb;
	unsigned short GrMr;
	unsigned short GgMg;
	unsigned short GbMb;
	unsigned short BrYr;
	unsigned short BgYg;
	unsigned short BbYb;
};

enum {
	KEY_WAKEUP,
	KEY_MAX,
};

typedef struct {
	int	(*OEM_sys_get_display_count) (int *value);

	int	(*OEM_sys_get_backlight_min_brightness) (int index, int *value);
	int	(*OEM_sys_get_backlight_max_brightness) (int index, int *value);
	int	(*OEM_sys_set_backlight_max_brightness) (int index, int value);
	int	(*OEM_sys_get_backlight_brightness) (int index, int *value, int power_saving);
	int	(*OEM_sys_set_backlight_brightness) (int index, int value, int power_saving);

	int	(*OEM_sys_set_backlight_dimming) (int index, int value);

	int	(*OEM_sys_get_backlight_acl_control) (int index, int *value);
	int	(*OEM_sys_set_backlight_acl_control) (int index, int value);

	int	(*OEM_sys_get_lcd_power) (int index, int *value);
	int	(*OEM_sys_set_lcd_power) (int index, int value);

	int	(*OEM_sys_get_image_enhance_mode) (int *value);
	int	(*OEM_sys_set_image_enhance_mode) (int value);
	int	(*OEM_sys_get_image_enhance_scenario) (int *value);
	int	(*OEM_sys_set_image_enhance_scenario) (int value);
	int	(*OEM_sys_get_image_enhance_tone) (int *value);
	int	(*OEM_sys_set_image_enhance_tone) (int value);
	int	(*OEM_sys_get_image_enhance_outdoor) (int *value);
	int	(*OEM_sys_set_image_enhance_outdoor) (int value);

	int	(*OEM_sys_get_image_enhance_tune) (int *value);
	int	(*OEM_sys_set_image_enhance_tune) (int value);

	int	(*OEM_sys_image_enhance_info) (int *value);

	int	(*OEM_sys_get_image_enhance_color_blind) (int *value);
	int	(*OEM_sys_set_image_enhance_color_blind) (void *value);

	int	(*OEM_sys_set_display_frame_rate) (int value);

	int	(*OEM_sys_set_auto_screen_tone) (int index, int value);
	int	(*OEM_sys_get_auto_screen_tone) (int index, int *value);
	int	(*OEM_sys_set_auto_screen_tone_force) (int index, int value);

	int	(*OEM_sys_get_uart_path) (int *value);
	int	(*OEM_sys_set_uart_path) (int value);

	int	(*OEM_sys_get_usb_path) (int *value);
	int	(*OEM_sys_set_usb_path) (int value);

	int	(*OEM_sys_get_haptic_motor_level_max) (int *value);
	int	(*OEM_sys_get_haptic_motor_level) (int *value);
	int	(*OEM_sys_set_haptic_motor_level) (int value);
	int	(*OEM_sys_set_haptic_motor_enable) (int value);
	int	(*OEM_sys_set_haptic_motor_oneshot) (int value);

	int	(*OEM_sys_get_haptic_vibetones_level_max) (int *value);
	int	(*OEM_sys_get_haptic_vibetones_level) (int *value);
	int	(*OEM_sys_set_haptic_vibetones_level) (int value);
	int	(*OEM_sys_set_haptic_vibetones_enable) (int value);
	int	(*OEM_sys_set_haptic_vibetones_oneshot) (int value);

	int	(*OEM_sys_get_battery_capacity) (int *value);
	int	(*OEM_sys_get_battery_capacity_raw) (int *value);
	int	(*OEM_sys_get_battery_charge_full) (int *value);
	int	(*OEM_sys_get_battery_charge_now) (int *value);
	int	(*OEM_sys_get_battery_present) (int *value);
	int	(*OEM_sys_get_battery_health) (int *value);
	int	(*OEM_sys_get_battery_polling_required) (int *value);
	int	(*OEM_sys_get_battery_support_insuspend_charging) (int *value);

	int	(*OEM_sys_get_jack_charger_online) (int *value);
	int	(*OEM_sys_get_jack_earjack_online) (int *value);
	int	(*OEM_sys_get_jack_earkey_online) (int *value);
	int	(*OEM_sys_get_jack_hdmi_online) (int *value);
	int	(*OEM_sys_get_jack_usb_online) (int *value);
	int	(*OEM_sys_get_jack_cradle_online) (int *value);
	int	(*OEM_sys_get_jack_tvout_online) (int *value);
	int	(*OEM_sys_get_jack_keyboard_online) (int *value);

	int     (*OEM_sys_get_hdmi_support) (int *value);

	int	(*OEM_sys_get_leds_torch_max_brightness) (int *value);
	int	(*OEM_sys_get_leds_torch_brightness) (int *value);
	int	(*OEM_sys_set_leds_torch_brightness) (int value);

	/* TODO: Change args type */
	int	(*OEM_sys_set_power_state) (int value);
	int	(*OEM_sys_set_power_lock) (int value);
	int	(*OEM_sys_get_power_lock_support)(int *value);

	/* TODO: Should determine enum values of wakeup_count nodes */
	int	(*OEM_sys_get_power_wakeup_count) (int *value);
	int	(*OEM_sys_set_power_wakeup_count) (int value);

	int	(*OEM_sys_get_memnotify_node) (char *node);
	int	(*OEM_sys_get_memnotify_victim_task) (int *value);
	int	(*OEM_sys_set_memnotify_threshold_lv1) (int value);
	int	(*OEM_sys_set_memnotify_threshold_lv2) (int value);

	int	(*OEM_sys_get_process_monitor_node) (char *node);
	int	(*OEM_sys_set_process_monitor_mp_pnp) (int value);
	int	(*OEM_sys_set_process_monitor_mp_vip) (int value);

	int	(*OEM_sys_get_cpufreq_cpuinfo_max_freq) (int *value);
	int	(*OEM_sys_get_cpufreq_cpuinfo_min_freq) (int *value);
	int	(*OEM_sys_get_cpufreq_scaling_max_freq) (int *value);
	int	(*OEM_sys_set_cpufreq_scaling_max_freq) (int value);
	int	(*OEM_sys_get_cpufreq_scaling_min_freq) (int *value);
	int	(*OEM_sys_set_cpufreq_scaling_min_freq) (int value);
	int	(*OEM_sys_get_cpufreq_power_max_freq) (int *value);
	int	(*OEM_sys_set_cpufreq_power_max_freq) (int value);
	int	(*OEM_sys_get_cpufreq_power_min_freq) (int *value);
	int	(*OEM_sys_set_cpufreq_power_min_freq) (int value);

	int	(*OEM_sys_set_cpufreq_id_min_freq) (char *str);
	int	(*OEM_sys_set_cpufreq_id_max_freq) (char *str);

	int	(*OEM_sys_set_pm_scenario) (char *value);

	int	(*OEM_sys_get_cpu_enable_max_number) (int *value);
	int	(*OEM_sys_set_cpu_enable_max_number) (int value);
	int	(*OEM_sys_get_cpu_fixed_number) (int *value);
	int	(*OEM_sys_set_cpu_fixed_number) (int value);

	int	(*OEM_sys_get_temperature_adc) (int *value);
	int	(*OEM_sys_get_temperature_value) (int *value);

	int	(*OEM_sys_get_dynamic_dispfreq) (int *value);
	int	(*OEM_sys_set_dynamic_dispfreq) (int value);

	int     (*OEM_sys_get_backlight_brightness_by_lux) (unsigned int lux, int *value, int force);

	int     (*OEM_sys_get_whitemagic_mode) (int index, int *value);
	int     (*OEM_sys_set_whitemagic_mode) (int index, int value);

	int     (*OEM_sys_get_lcd_cabc) (int index, int *value);
	int     (*OEM_sys_set_lcd_cabc) (int index, int value);

	int	(*OEM_sys_set_irled_control) (char *value);
	int	(*OEM_sys_set_svcled_color) (int rgb, int led_on_ms, int led_off_ms);
	int     (*OEM_sys_set_svcled_color)(int val);
	int     (*OEM_sys_get_cover_status) (char *value);

	int     (*OEM_sys_get_hardkey_backlight) (int *value);
	int     (*OEM_sys_set_hardkey_backlight) (int value);

	int     (*OEM_sys_get_touchscreen_clear_cover) (int *value);
	int     (*OEM_sys_set_touchscreen_clear_cover) (int value);
	int     (*OEM_sys_get_touchscreen_glove_mode) (int *value);
	int     (*OEM_sys_set_touchscreen_glove_mode) (int value);

	int     (*OEM_sys_get_touchkey_flip_mode) (int *value);
	int     (*OEM_sys_set_touchkey_flip_mode) (int value);
	int     (*OEM_sys_get_touchkey_glove_mode) (int *value);
	int     (*OEM_sys_set_touchkey_glove_mode) (int value);

	int     (*OEM_sys_get_backlight_hbm_control) (int index, int *value);
	int     (*OEM_sys_set_backlight_hbm_control) (int index, int value);

	int (*OEM_sys_get_leds_flash_brightness) (int *value);
	int (*OEM_sys_set_leds_flash_brightness) (int value);

	int     (*OEM_sys_get_backlight_elvss_control) (int index, int *value);
	int     (*OEM_sys_set_backlight_elvss_control) (int index, int value);

	int     (*OEM_sys_set_key) (int index, int value);

	int (*OEM_sys_set_backlight_max_brightness) (int index, int value);
	int (*OEM_sys_set_auto_screen_tone_force) (int index, int value);

	int (*OEM_sys_get_extcon) (int type, int *value);
	int (*OEM_sys_set_extcon) (int type, int value);
} OEM_sys_devman_plugin_interface;

const OEM_sys_devman_plugin_interface *OEM_sys_get_devman_plugin_interface();

#endif	/* __DEVMAN_PLUGIN_INTF_H__ */
