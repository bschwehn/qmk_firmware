/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef DEBOUNCE
#define DEBOUNCE 5

#define PERMISSIVE_HOLD

#undef RGB_DISABLE_TIMEOUT
#define RGB_DISABLE_TIMEOUT 900000

#define USB_SUSPEND_WAKEUP_DELAY 0
#define HOLD_ON_OTHER_KEY_PRESS
#define FIRMWARE_VERSION u8"q0BPV/o4xl4"
#define RGB_MATRIX_STARTUP_SPD 60
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 600
//#undef AUDIO_ENABLE
