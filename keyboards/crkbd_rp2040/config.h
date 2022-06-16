/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

#pragma once
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x9040
#define DEVICE_VER      0x0001
#define MANUFACTURER    QMK Community
#define PRODUCT         Marz38 Keyboard
#define MATRIX_ROW_PINS { GP4, GP5, GP6, GP7 }
#define MATRIX_COL_PINS { GP29, GP28, GP27, GP26, GP18, GP20 }
#define DIODE_DIRECTION COL2ROW
#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN GP1
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
#define I2C1_SDA_PIN GP2
#define I2C1_SCL_PIN GP3
#define I2C_DRIVER I2CD2
//#define SPLIT_HAND_PIN GP22

/* /\* USB Device descriptor parameter *\/ */
/* #define VENDOR_ID    0x4653 */
/* #define PRODUCT_ID   0x0001 */
/* #define DEVICE_VER   0x0001 */
/* #define MANUFACTURER foostan */
/* #define PRODUCT      Corne */

/* /\* key matrix size *\/ */
/* // Rows are doubled-up */
/* #define MATRIX_ROWS  8 */
/* #define MATRIX_COLS  6 */
/* #define MATRIX_ROW_PINS \ */
/*     { D4, C6, D7, E6 } */

/* // wiring of each half */
/* #define MATRIX_COL_PINS \ */
/*     { F4, F5, F6, F7, B1, B3 } */
/* // #define MATRIX_COL_PINS { B2, B3, B1, F7, F6, F5, F4 } //uncomment this line and comment line above if you need to reverse left-to-right key order */

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define USE_SERIAL
