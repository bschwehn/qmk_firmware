/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef DEBOUNCE
#define DEBOUNCE 5

#undef TAPPING_TERM
#define TAPPING_TERM 172

#define PERMISSIVE_HOLD

#undef RGB_DISABLE_TIMEOUT
#define RGB_DISABLE_TIMEOUT 900000

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 202

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 14

#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 80

#define FIRMWARE_VERSION u8"VWRRX/WPeWP"
#undef RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_STARTUP_SPD 60
// custom
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 400
#define IGNORE_MOD_TAP_INTERRUPT
