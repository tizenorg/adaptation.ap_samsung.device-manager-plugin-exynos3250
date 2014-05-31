#!/bin/sh

#--------------------------------------
#   time
#--------------------------------------
TIME_DEBUG=$1/time
/bin/mkdir -p ${TIME_DEBUG}

/bin/date > ${TIME_DEBUG}/status
/bin/date +%s >> ${TIME_DEBUG}/status
/bin/cat /sys/class/rtc/rtc0/since_epoch >> ${TIME_DEBUG}/status

/bin/cat /sys/kernel/debug/s2m_rtc_debug/* >> ${TIME_DEBUG}/s2m_rtc_debug

