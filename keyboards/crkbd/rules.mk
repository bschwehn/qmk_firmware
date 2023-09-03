# MCU name
MCU = RP2040
BOOTLOADER = rp2040
ALLOW_WARNINGS = yes
SERIAL_DRIVER = vendor
WS2812_DRIVER = vendor
PICO_INTRINSICS_ENABLED = no # ATM Unsupported by ChibiOS
SPLIT_KEYBOARD = yes
# MCU = atmega32u4

# # Bootloader selection
# BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#

DEFAULT_FOLDER = crkbd/rev1

RGBLIGHT_SUPPORTED = yes
RGB_MATRIX_SUPPORTED = yes

LAYOUTS = split_3x5_3 split_3x6_3
