CONSOLE_ENABLE = no
COMMAND_ENABLE = no
AUDIO_ENABLE = no
WEBUSB_ENABLE = no
ORYX_ENABLE = no
DYNAMIC_MACRO_ENABLE = no
TAP_DANCE_ENABLE = yes
# custom
NKRO_ENABLE = no           # Enable N-Key Rollover
LEADER_ENABLE = yes
COMBO_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
SRC += features/caps_word.c
SRC += features/achordion.c
SRC += features/layer_lock.c
LAYER_LOCK_ENABLE = yes

MOUSEKEY_ENABLE = yes    # Mouse keys
RGBLIGHT_ENABLE = yes    # Enable WS2812 RGB underlight.
OLED_ENABLE     = yes
OLED_DRIVER     = SSD1306
LTO_ENABLE      = yes
# https://docs.qmk.fm/#/squeezing_avr?id=squeezing-the-most-out-of-avr
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
AVR_USE_MINIMAL_PRINTF = yes
CAPS_WORD_ENABLE = no
