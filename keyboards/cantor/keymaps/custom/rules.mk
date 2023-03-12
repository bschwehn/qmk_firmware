CONSOLE_ENABLE = no
COMMAND_ENABLE = no
AUDIO_ENABLE = no
WEBUSB_ENABLE = yes
ORYX_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
TAP_DANCE_ENABLE = yes
# custom
LEADER_ENABLE = yes
COMBO_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
SRC += features/caps_word.c
SRC += features/achordion.c
SRC += features/layer_lock.c
