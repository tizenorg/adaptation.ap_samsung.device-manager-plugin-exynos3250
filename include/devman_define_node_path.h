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


#ifndef __DEVMAN_DEFINE_NODE_PATH_H
#define __DEVMAN_DEFINE_NODE_PATH_H

#define BACKLIGHT_PATH "/sys/class/backlight/"
#define BACKLIGHT_MAX_BRIGHTNESS_PATH	BACKLIGHT_PATH"%s/max_brightness"
#define BACKLIGHT_MIN_BRIGHTNESS_PATH	BACKLIGHT_PATH"%s/min_brightness"
#define BACKLIGHT_BRIGHTNESS_PATH 	BACKLIGHT_PATH"%s/brightness"
#define BACKLIGHT_DIMMING_PATH	BACKLIGHT_PATH"%s/dimming"
#define BACKLIGHT_OVERHEATING_PATH  BACKLIGHT_PATH"%s/overheating"
#define MDNIE_BACKLIGHT_BRIGHTNESS_PATH        BACKLIGHT_PATH"mdnie-bl/brightness"
#define MDNIE_BACKLIGHT_OVERHEATING_PATH  BACKLIGHT_PATH"mdnie-bl/overheating"

#define LCD_PATH  "/sys/class/lcd/"
#define LCD_WM_CONTROL_PATH	LCD_PATH"%s/wm_mode"
#define LCD_CABC_CONTROL_PATH	LCD_PATH"%s/cabc"
#define LCD_ACL_CONTROL_PATH	LCD_PATH"%s/acl_control"
#define LCD_HBM_CONTROL_PATH	LCD_PATH"%s/hbm_control"
#define LCD_ELVSS_CONTROL_PATH	LCD_PATH"%s/elvss_control"
#define LCD_POWER_PATH			LCD_PATH"%s/lcd_power"
#define IMAGE_ENHANCE_PATH			"/sys/class/extension/mdnie/%s"
#define IMAGE_ENHANCE_PATH_INFO			"/sys/class/extension/mdnie"

#define DRM_PATH	"/sys/devices/platform/exynos-drm/drm/card0"

#define DISPLAY_FRAME_RATE_PATH        "/sys/class/graphics/fb0/dynamic_fps"
#define DISPLAY_MISC_LCD_FPS_PATH        "/sys/class/sec/sec_misc/lcd_fps"

#define UART_PATH			"/sys/devices/virtual/sec/switch/uart_sel"
#define USB_PATH			"/sys/devices/virtual/sec/switch/usb_sel"
#define UART_PATH_TRATS			"/sys/devices/platform/uart-select/path"
#define USB_PATH_TRATS			"/sys/devices/platform/usb-select/path"

#define MUIC_ADC_ENABLE_PATH			"/sys/devices/virtual/sec/switch/adc_enable"
#define MUIC_USBID_PATH			"/sys/devices/virtual/sec/switch/adc"

#define COVER_STATUS_PATH		"/sys/class/flip/hall_ic/cover_status"
#define HAPTIC_MOTOR_LEVEL_PATH	"/sys/class/haptic/motor/level"
#define HAPTIC_MOTOR_LEVEL_MAX_PATH	"/sys/class/haptic/motor/level_max"
#define HAPTIC_MOTOR_ENABLE_PATH	"/sys/class/haptic/motor/enable"
#define HAPTIC_MOTOR_ONESHOT_PATH	"/sys/class/haptic/motor/oneshot"

#define KEY_WAKEUP_ENABLE_PATH "/sys/class/sec/sec_key/wakeup_keys"

#define BATTERY_CAPACITY_PATH		"/sys/class/power_supply/battery/capacity"
#define BATTERY_CAPACITY_RAW_PATH	"/sys/class/power_supply/battery/capacity_raw"
#define BATTERY_CHARGE_FULL_PATH	"/sys/class/power_supply/battery/charge_full"
#define BATTERY_CHARGE_NOW_PATH		"/sys/class/power_supply/battery/charge_now"
#define BATTERY_PRESENT_PATH		"/sys/class/power_supply/battery/present"
#define BATTERY_HEALTH_PATH		"/sys/class/power_supply/battery/health"

#define JACK_CHARGER_ONLINE_PATH	"/sys/devices/platform/jack/charger_online"
#define JACK_EARJACK_ONLINE_PATH	"/sys/class/switch/earjack/state"
#define JACK_EARKEY_ONLINE_PATH		"/sys/class/switch/earkey/state"
#define JACK_HDMI_ONLINE_PATH		"/sys/devices/platform/jack/hdmi_online"
#define JACK_USB_ONLINE_PATH		"/sys/devices/virtual/switch/usb_cable/state"
#define JACK_CRADLE_ONLINE_PATH		"/sys/class/switch/cradle/state"
#define JACK_TVOUT_ONLINE_PATH		"/sys/devices/platform/jack/tvout_online"
#define JACK_KEYBOARD_ONLINE_PATH		"/sys/devices/platform/jack/keyboard_online"

#define LEDS_TORCH_MAX_BRIGHTNESS_PATH	"/sys/class/leds/torch-sec1/max_brightness"
#define LEDS_TORCH_BRIGHTNESS_PATH	"/sys/class/leds/torch-sec1/brightness"

#define POWER_STATE_PATH		"/sys/power/state"
#define POWER_AUTOSLEEP_PATH		"/sys/power/autosleep"
#define POWER_UNLOCK_PATH		"/sys/power/wake_unlock"
#define POWER_LOCK_PATH		"/sys/power/wake_lock"
#define POWER_WAKEUP_COUNT_PATH		"/sys/power/wakeup_count"

#define MEMNOTIFY_NODE			"/dev/memnotify"
#define MEMNOTIFY_VICTIM_TASK_PATH	"/sys/class/memnotify/victim_task"
#define MEMNOTIFY_THRESHOLD_LV1_PATH	"/sys/class/memnotify/threshold_lv1"
#define MEMNOTIFY_THRESHOLD_LV2_PATH	"/sys/class/memnotify/threshold_lv2"

#define TOUCH_EVENT_NODE		"/dev/event2"

#define PROCESS_MONITOR_NODE		"/dev/pmon"
#define PROCESS_MONITOR_MP_PNP_PATH	"/sys/class/pmon/mp_pnp"
#define PROCESS_MONITOR_MP_VIP_PATH	"/sys/class/pmon/mp_vip"

#define CPU_ENABLE_MAX_NUMBER_PATH	"/sys/devices/system/cpu/cpu0/rq-stats/max_cpu_num_lock"
#define CPU_ENABLE_MIN_NUMBER_PATH	"/sys/devices/system/cpu/cpu0/rq-stats/min_cpu_num_lock"
#define CPU_ENABLE_FIXED_NUMBER_PATH	"/sys/devices/system/cpu/cpu0/rq-stats/hotplug_lock"

#define CPUFREQ_CPUINFO_MAX_FREQ_PATH	"/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq"
#define CPUFREQ_CPUINFO_MIN_FREQ_PATH	"/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_min_freq"
#define CPUFREQ_SCALING_MAX_FREQ_PATH	"/sys/devices/system/cpu/cpufreq/pmqos/cpufreq_max"
#define CPUFREQ_SCALING_MIN_FREQ_PATH	"/sys/devices/system/cpu/cpufreq/pmqos/cpufreq_min"
#define CPUFREQ_POWER_MAX_FREQ_PATH	"/sys/devices/system/cpu/cpufreq/pmqos/cpufreq_max"
#define CPUFREQ_POWER_MIN_FREQ_PATH	"/sys/devices/system/cpu/cpufreq/pmqos/cpufreq_min"
#define CPUFREQ_ID_MAX_FREQ_PATH		"/sys/devices/system/cpu/cpufreq/pmqos/cpufreq_max"
#define CPUFREQ_ID_MIN_FREQ_PATH		"/sys/devices/system/cpu/cpufreq/pmqos/cpufreq_min"

#define GPUFREQ_ID_MAX_FREQ_PATH		"/sys/class/kgsl/kgsl-3d0/max_pwrlevel"
#define GPUFREQ_ID_MIN_FREQ_PATH		"/sys/class/kgsl/kgsl-3d0/min_pwrlevel"


/* For Non-Interactive settings */
#define CPUFREQ_GOVERNOR_PATH	"/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor"
#define CPUFREQ_ONDEMAND_SAMPLING_RATE	"/sys/devices/system/cpu/cpufreq/ondemand/sampling_rate"
#define CPUFREQ_ONDEMAND_OPTIMAL_FREQ	"/sys/devices/system/cpu/cpufreq/ondemand/optimal_freq"
#define CPUFREQ_ONDEMAND_SYNC_FREQ	"/sys/devices/system/cpu/cpufreq/ondemand/sync_freq"


#define TEMPERATURE_ADC_PATH	"/sys/devices/platform/sec-thermistor/temp-adc"
#define TEMPERATURE_VALUE_PATH 	"/sys/devices/platform/sec-thermistor/temperature"

#define IRLED_CONTROL_PATH 	"/sys/class/sec/sec_ir/ir_send"

#define SERVICE_LED_R_PATH "/sys/class/sec/led/led_r"
#define SERVICE_LED_G_PATH "/sys/class/sec/led/led_g"
#define SERVICE_LED_B_PATH "/sys/class/sec/led/led_b"

#define SERVICE_LED_BLINK_PATH "/sys/class/sec/led/led_blink"
#define SERVICE_LED_PATTERN_PATH "/sys/class/sec/led/led_pattern"

#define KEY_MANUAL_RESET_PMIC_PATH "/sys/bus/platform/drivers/max77686-pmic/max77686-pmic/mrstb"
#define KEY_MANUAL_RESET_SAFEOUT_PATH "/sys/bus/platform/drivers/max77693-safeout/max77693-safeout/mrstb"

#define TOUCHKEY_LED_PATH "/sys/devices/virtual/sec/sec_touchkey/brightness"
#define TOUCHKEY_GLOVE_MODE_PATH "/sys/devices/virtual/sec/sec_touchkey/glove_mode"
#define TOUCHKEY_FLIP_MODE_PATH "/sys/devices/virtual/sec/sec_touchkey/flip_mode"

#define TOUCHSCREEN_GLOVE_MODE_PATH "/sys/devices/virtual/sec/sec_touchscreen/glove_mode_enable"
#define TOUCHSCREEN_CLEAR_COVER_PATH "/sys/devices/virtual/sec/sec_touchscreen/closed_cover_enable"

#define BATTERY_TECHNOLOGY_PATH		"/sys/class/power_supply/battery/technology"
#define BATTERY_TEMPERATURE_PATH		"/sys/class/power_supply/battery/temp"
#define BATTERY_VOLTAGE_PATH			"/sys/class/power_supply/battery/voltage_now"

#define LEDS_FLASH_MOVIE_BRIGHTNESS_PATH	"/sys/class/camera/flash/movie_brightness"

#endif /* __DEVMAN_DEFINE_NODE_PATH_H */
