# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
AUDIO_ENABLE = no
WEBUSB_ENABLE = yes
ORYX_ENABLE = yes
DYNAMIC_MACRO_ENABLE = no
TAP_DANCE_ENABLE = no
SRC = matrix.c
# custom
LEADER_ENABLE = yes
COMBO_ENABLE = yes
KEY_OVERRIDE_ENABLE = no
SRC += features/caps_word.c
SRC += features/achordion.c
SRC += features/layer_lock.c
CONSOLE_ENABLE = no
