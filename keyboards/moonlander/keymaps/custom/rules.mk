# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
AUDIO_ENABLE = no
WEBUSB_ENABLE = yes
ORYX_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
TAP_DANCE_ENABLE = yes
SRC = matrix.c
# custom
LEADER_ENABLE = yes
COMBO_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
SRC += features/caps_word.c
SRC += features/achordion.c
SRC += features/layer_lock.c
