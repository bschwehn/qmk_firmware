/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef DEBOUNCE
#define DEBOUNCE 5

#undef RGB_DISABLE_TIMEOUT
#define RGB_DISABLE_TIMEOUT 900000

#define USB_SUSPEND_WAKEUP_DELAY 0
#define AUTO_SHIFT_TIMEOUT 135
#define NO_AUTO_SHIFT_TAB
#define HOLD_ON_OTHER_KEY_PRESS
#define FIRMWARE_VERSION u8"q0BPV/OgmL9"
#define RGB_MATRIX_STARTUP_SPD 60
