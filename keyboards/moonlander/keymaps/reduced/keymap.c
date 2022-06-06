#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_uk.h"
#include "features/caps_word.h"
#include "features/achordion.h"
#include "features/layer_lock.h"
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define MOON_LED_LEVEL LED_LEVEL
#define NA KC_TRANSPARENT

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
};


enum custom_combo {
    CUSTOM_QU = ML_SAFE_RANGE + 5,
    CUSTOM_AUML,
    CUSTOM_UUML,
    CUSTOM_OUML,
    CUSTOM_BSPACE,
    CUSTOM_END_CAPS,
    CUSTOM_ESC,
    CUSTOM_ENTER,
    CUSTOM_LAST
};

enum custom_ext {
    LLOCK = CUSTOM_LAST
};

enum tap_dance_codes {
  DANCE_0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    NA, NA, NA, NA, NA, NA, NA,    NA, NA, NA, NA, NA, NA, NA,
    NA,         KC_Q,           KC_W,           LT(4,KC_F),     LT(4,KC_P),     KC_B,           NA,                                    NA,        KC_J,           LT(3,KC_L),     LT(3,KC_U),     KC_Y,           NA,    NA,
    NA,  MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_R), MT(MOD_LSFT, KC_S), MT(MOD_LCTL, KC_T), KC_G, NA,   NA,        KC_M,           MT(MOD_RCTL, KC_N),MT(MOD_RSFT, KC_E),MT(MOD_LALT, KC_I),MT(MOD_RGUI, KC_O),KC_APPLICATION,
    NA,        LT(2,KC_Z),     LT(2,KC_X),     LT(1,KC_C),     LT(1,KC_D),     KC_V,   KC_K,           LT(1,KC_H),     LT(1,KC_COMMA), KC_DOT,         UK_DQUO,        NA,
    OSL(9),    TO(2),    KC_RALT,        KC_LGUI,        OSL(1),         LLOCK, KC_LEAD,          OSM(MOD_LSFT),  KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,
   KC_SPACE,       MT(MOD_LCTL, KC_DELETE), MT(MOD_LSFT, KC_ENTER),                MT(MOD_RSFT, KC_ENTER),MT(MOD_LCTL, KC_BSPACE),KC_BSPACE
  ),
  [1] = LAYOUT_moonlander(
    NA, NA, NA, NA, NA, NA, NA,    NA, NA, NA, NA, NA, NA, TO(0),
    NA, NA, UK_BSLS,        UK_LABK,        UK_RABK,        UK_PERC,        UK_BRKP,                                        NA,         UK_AT,          UK_QUES,        UK_PIPE,        UK_ASTR,        UK_GRV,         KC_PSCREEN,
    TO(0),          MT(MOD_LGUI, UK_COLN), MT(MOD_LALT, UK_SCLN), MT(MOD_LSFT, UK_LCBR), MT(MOD_LCTL, UK_RCBR),    UK_PLUS,        ST_MACRO_0, NA,         UK_CIRC,        MT(MOD_RCTL, UK_EQL),MT(MOD_RSFT, UK_AMPR),MT(MOD_LALT, UK_DLR),   MT(MOD_RGUI, UK_MINS),KC_TRANSPARENT,
    NA, UK_LPRN,        UK_RPRN,        UK_LBRC,        UK_RBRC,        UK_MINS,                                        UK_TILD,        UK_EXLM,        UK_UNDS,        UK_SLSH,        UK_HASH,        KC_RALT,
    NA, KC_TRANSPARENT, KC_INSERT,      UK_LPRN,        TO(0),          KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_HOME,        KC_PGDOWN,      KC_PGUP,        KC_END,         KC_SCROLLLOCK,
    KC_SPACE,       UK_SCLN,        UK_COLN,                        UK_UNDS,        KC_LPRN,        KC_ENTER
  ),
  [2] = LAYOUT_moonlander(
    WEBUSB_PAIR,    KC_MS_WH_UP,    KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     KC_MS_BTN3,     KC_MS_WH_LEFT,                                  NA, NA, NA, NA, NA, NA, TO(0),
    NA, KC_MS_WH_DOWN,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_ACCEL0,   KC_MS_WH_RIGHT,                                 NA, LCTL(KC_Z),     LSFT(KC_INSERT),LCTL(KC_INSERT),LSFT(KC_DELETE),LCTL(KC_Y),     KC_PSCREEN,
    TO(0),          NA, NA, NA, NA, KC_MS_ACCEL1,   NA,                                                                 NA, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_PAUSE,       NA,
    NA, KC_PC_UNDO,     KC_PC_CUT,      KC_PC_COPY,     KC_PC_PASTE,    KC_MS_ACCEL2,                                   KC_HOME,        KC_PGDOWN,      KC_PGUP,        KC_END,         KC_INSERT,      NA,
    NA, NA, NA, NA, NA, NA,                                                                                                 NA, NA, NA, NA, NA, NA,
    KC_MS_WH_UP,    KC_MS_WH_DOWN,  NA,                 NA, LCTL(KC_MS_WH_DOWN),LCTL(KC_MS_WH_UP)
  ),
  [3] = LAYOUT_moonlander(
    NA, NA, NA, NA, NA, NA, NA,    NA, NA, NA, NA, NA, NA, NA,
    NA, LSFT(KC_TAB),   KC_F1,          KC_F2,          KC_F3,          KC_F10,         NA,                                 NA, NA, NA, NA, NA, NA, NA,
    NA, KC_TAB,         KC_F4,          KC_F5,          KC_F6,          KC_F11,         NA,                                                                 NA, NA, NA, NA, NA, NA, NA,
    NA, KC_APPLICATION, KC_F7,          KC_F8,          KC_F9,          KC_F12,                                         NA, NA, NA, NA, NA, NA,
    NA, NA, NA, NA, NA, NA,                                                                                                 NA, NA, NA, NA, NA, NA,
    NA, NA, NA,                 NA, NA, NA
  ),
  [4] = LAYOUT_moonlander(
    NA, NA, NA, NA, NA, NA, NA,                                 NA, NA, NA, NA, NA, NA, NA,
    NA, NA, NA, NA, NA, NA, NA,                                 NA, UK_0,           UK_1,           UK_2,           UK_3,           UK_ASTR,   NA,
    NA, NA, NA, NA, NA, NA, NA,                                                                 NA, KC_KP_MINUS,    UK_4,           UK_5,           UK_6,           KC_KP_DOT,      NA,
    NA, NA, NA, NA, NA, NA,                                 KC_KP_PLUS,     UK_7,           UK_8,           UK_9,           KC_KP_COMMA,    NA,
    NA, NA, NA, NA, NA, NA,                                                                                                 NA, NA, NA, NA, NA, NA,
    NA, NA, NA,                 NA, NA, NA
  ),
  [5] = LAYOUT_moonlander(
    NA, NA, NA, NA, NA, NA, NA,                                 NA, NA, NA, NA, NA, NA, TO(0),
    NA, LSFT(KC_TAB),   KC_F1,          KC_F2,          KC_F3,          KC_F10,         NA,                                 NA, UK_0,           UK_1,           UK_2,           UK_3,           UK_ASTR,   NA,
    TO(0),          KC_TAB,         KC_F4,          KC_F5,          KC_F6,          KC_F11,         NA,                                                                 NA, KC_KP_MINUS,    UK_4,           UK_5,           UK_6,           KC_KP_DOT,      NA,
    NA, KC_APPLICATION, KC_F7,          KC_F8,          KC_F9,          KC_F12,                                         KC_KP_PLUS,     UK_7,           UK_8,           UK_9,           KC_KP_COMMA,    NA,
    NA, NA, NA, NA, NA, NA,                                                                                                 NA, NA, NA, NA, NA, NA,
    NA, NA, NA,                 NA, NA, NA
  ),
  [6] = LAYOUT_moonlander(
    NA, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           NA,                                 NA, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           TO(0),
    NA, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           NA,                                 NA, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           NA,
    NA, KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           NA,                                                                 NA, KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      NA,
    NA, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       NA,
    NA, NA, NA, NA, TO(0),          NA,                                                                                                 NA, NA, NA, NA, NA, NA,
    NA, NA, NA,                 NA, NA, NA
  ),
  [7] = LAYOUT_moonlander(
    NA, NA, NA, NA, NA, NA, NA,                                 NA, NA, NA, KC_KP_SLASH,    KC_KP_ASTERISK, NA, TO(0),
    NA, NA, NA, NA, NA, NA, NA,                                 NA, NA, KC_7,           KC_8,           KC_9,           KC_KP_PLUS,     NA,
    TO(0),          KC_LGUI,        KC_LALT,        KC_LSHIFT,      KC_LCTRL,       NA, NA,                                                                 NA, NA, KC_4,           KC_5,           KC_6,           KC_KP_MINUS,    NA,
    NA, NA, NA, NA, NA, NA,                                 NA, KC_1,           KC_2,           KC_3,           KC_EQUAL,       NA,
    NA, NA, NA, NA, NA, NA,                                                                                                 NA, KC_0,           UK_COMM,        KC_KP_DOT,      NA, NA,
    NA, NA, NA,                 NA, NA, NA
  ),
  [8] = LAYOUT_moonlander(
    NA, NA, NA, NA, NA, NA, NA,                                 NA, NA, NA, NA, NA, NA, TO(0),
    NA, NA, NA, NA, NA, NA, NA,                                 NA, NA, KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,NA, NA,
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          NA,                                                                 RGB_TOG,        NA, KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,NA, NA,
    KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,                                         NA, NA, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,NA, NA,
    NA, NA, NA, LGUI(LSFT(KC_LBRACKET)),LGUI(LSFT(KC_RBRACKET)),NA,                                                                                                 NA, NA, NA, NA, NA, NA,
    NA, NA, NA,                 NA, NA, NA
  ),
  [9] = LAYOUT_moonlander(
    KC_SYSTEM_POWER,KC_SYSTEM_SLEEP,KC_SYSTEM_WAKE, NA, NA, NA, RESET,                                          NA, NA, NA, NA, NA, NA, TO(0),
    DYN_REC_STOP,   DYN_REC_START1, DYN_MACRO_PLAY1,NA, NA, NA, NA,                                 NA, NA, RGB_HUI,        RGB_HUD,        RGB_MOD,        RGB_SLD,        NA,
    TO(0),          NA, NA, NA, NA, NA, NA,                                                                 NA, AU_TOG,         RGB_VAI,        RGB_VAD,        TOGGLE_LAYER_COLOR,RGB_TOG,        NA,
    NA, NA, NA, NA, NA, NA,                                 NA, RGB_SAI,        RGB_SAD,        MOON_LED_LEVEL, NA, NA,
    NA, NA, NA, NA, NA, NA,                                                                                                 NA, RGB_SPI,        RGB_SPD,        NA, NA, NA,
    NA, NA, NA,                 NA, NA, NA
  )
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {0,0,0}, {0,0,0}, {249,255,232}, {0,0,0}, {14,255,255}, {0,0,0}, {146,255,255}, {129,255,255}, {146,255,255}, {14,255,255}, {0,0,0}, {146,255,255}, {89,255,255}, {146,255,255}, {169,120,255}, {0,0,0}, {146,255,255}, {152,218,204}, {146,255,255}, {129,255,255}, {0,0,0}, {146,255,255}, {249,255,232}, {146,255,255}, {14,255,255}, {0,0,0}, {146,255,255}, {146,255,255}, {146,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {146,255,255}, {0,255,255}, {152,218,204}, {14,255,255}, {28,244,245}, {0,0,0}, {28,244,245}, {0,0,0}, {195,255,255}, {0,0,0}, {0,0,0}, {129,255,255}, {46,218,204}, {195,255,255}, {0,0,0}, {146,255,255}, {89,255,255}, {46,218,204}, {195,255,255}, {0,0,0}, {146,255,255}, {152,218,204}, {46,218,204}, {195,255,255}, {0,0,0}, {146,255,255}, {249,255,232}, {146,255,255}, {14,255,255}, {0,0,0}, {146,255,255}, {146,255,255}, {146,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,255,255}, {46,218,204}, {14,255,255} },

    [1] = { {146,255,255}, {146,255,255}, {249,255,232}, {146,255,255}, {146,255,255}, {169,120,255}, {146,255,255}, {14,255,255}, {169,120,255}, {146,255,255}, {169,120,255}, {14,255,255}, {14,255,255}, {146,255,255}, {35,255,255}, {169,120,255}, {110,218,204}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {110,218,204}, {146,255,255}, {146,255,255}, {146,255,255}, {169,120,255}, {14,255,255}, {14,255,255}, {14,255,255}, {146,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {146,255,255}, {146,255,255}, {167,255,255}, {146,255,255}, {35,255,255}, {0,0,0}, {169,120,255}, {14,255,255}, {14,255,255}, {14,255,255}, {46,218,204}, {169,120,255}, {14,255,255}, {14,255,255}, {14,255,255}, {146,255,255}, {169,120,255}, {14,255,255}, {14,255,255}, {14,255,255}, {146,255,255}, {169,120,255}, {14,255,255}, {14,255,255}, {14,255,255}, {46,218,204}, {169,120,255}, {14,255,255}, {14,255,255}, {14,255,255}, {146,255,255}, {169,120,255}, {169,120,255}, {146,255,255}, {169,120,255}, {14,255,255}, {146,255,255} },

    [2] = { {169,120,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,255,123}, {152,255,123}, {0,0,0}, {243,135,251}, {0,0,0}, {85,203,158}, {152,255,255}, {0,0,0}, {35,255,255}, {0,0,0}, {152,255,255}, {152,255,255}, {0,0,0}, {95,218,204}, {0,0,0}, {85,203,158}, {152,255,255}, {0,0,0}, {88,81,255}, {0,0,0}, {85,203,158}, {188,255,255}, {188,255,255}, {188,255,255}, {152,255,123}, {152,255,123}, {0,0,0}, {152,255,123}, {152,255,123}, {0,0,0}, {0,0,0}, {146,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {242,194,244}, {14,255,255}, {46,218,204}, {0,0,0}, {0,0,0}, {35,255,255}, {110,218,204}, {35,255,255}, {0,0,0}, {0,0,0}, {95,218,204}, {110,218,204}, {35,255,255}, {0,0,0}, {0,0,0}, {88,81,255}, {110,218,204}, {35,255,255}, {0,0,0}, {0,0,0}, {243,135,251}, {110,218,204}, {35,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {243,135,251}, {243,135,251}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {28,244,245}, {28,244,245}, {28,244,245}, {0,0,0}, {0,0,0}, {110,218,204}, {198,218,204}, {110,218,204}, {0,0,0}, {0,0,0}, {110,218,204}, {110,218,204}, {110,218,204}, {0,0,0}, {0,0,0}, {110,218,204}, {110,218,204}, {110,218,204}, {0,0,0}, {0,0,0}, {110,172,210}, {110,172,210}, {198,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {129,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {89,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {249,255,232}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {129,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {89,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {249,255,232}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {14,255,255}, {46,218,204}, {46,218,204}, {0,0,0}, {0,0,0}, {110,218,204}, {110,218,204}, {110,218,204}, {0,0,0}, {0,0,0}, {110,218,204}, {110,218,204}, {110,218,204}, {0,0,0}, {0,0,0}, {110,218,204}, {110,218,204}, {110,218,204}, {0,0,0}, {0,0,0}, {110,218,204}, {14,255,255}, {14,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [5] = { {0,0,0}, {0,0,0}, {249,255,232}, {0,0,0}, {0,0,0}, {0,0,0}, {28,244,245}, {28,244,245}, {28,244,245}, {0,0,0}, {0,0,0}, {110,218,204}, {198,218,204}, {110,218,204}, {0,0,0}, {0,0,0}, {110,218,204}, {110,218,204}, {110,218,204}, {0,0,0}, {0,0,0}, {110,218,204}, {110,218,204}, {110,218,204}, {0,0,0}, {0,0,0}, {110,218,204}, {110,218,204}, {198,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {14,255,255}, {46,218,204}, {46,218,204}, {0,0,0}, {0,0,0}, {110,218,204}, {110,218,204}, {110,218,204}, {0,0,0}, {0,0,0}, {110,218,204}, {110,218,204}, {110,218,204}, {0,0,0}, {0,0,0}, {110,218,204}, {110,218,204}, {110,218,204}, {0,0,0}, {0,0,0}, {110,218,204}, {14,255,255}, {14,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [6] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {249,255,232}, {249,255,232}, {249,255,232}, {0,0,0}, {0,0,0}, {249,255,232}, {249,255,232}, {249,255,232}, {0,0,0}, {0,0,0}, {249,255,232}, {249,255,232}, {249,255,232}, {0,0,0}, {0,0,0}, {249,255,232}, {249,255,232}, {249,255,232}, {0,0,0}, {0,0,0}, {249,255,232}, {249,255,232}, {249,255,232}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {249,255,232}, {249,255,232}, {249,255,232}, {0,0,0}, {0,0,0}, {249,255,232}, {249,255,232}, {249,255,232}, {0,0,0}, {0,0,0}, {249,255,232}, {249,255,232}, {249,255,232}, {0,0,0}, {0,0,0}, {249,255,232}, {249,255,232}, {249,255,232}, {0,0,0}, {0,0,0}, {249,255,232}, {249,255,232}, {249,255,232}, {35,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [7] = { {0,0,0}, {0,0,0}, {249,255,232}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {95,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {95,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {95,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {95,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {169,120,255}, {169,120,255}, {169,120,255}, {0,0,0}, {169,120,255}, {110,218,204}, {110,218,204}, {110,218,204}, {14,255,255}, {169,120,255}, {110,218,204}, {110,218,204}, {110,218,204}, {35,255,255}, {0,0,0}, {110,218,204}, {110,218,204}, {110,218,204}, {35,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {169,120,255}, {14,255,255}, {85,203,158}, {0,0,0} },

    [8] = { {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {249,228,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {249,228,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {233,218,217}, {32,255,234}, {146,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {233,218,217}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {35,255,255}, {154,255,255}, {249,228,255}, {0,0,0}, {0,0,0}, {35,255,255}, {154,255,255}, {249,228,255}, {0,0,0}, {0,0,0}, {35,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {35,255,255}, {0,0,0}, {0,0,0}, {233,218,217}, {32,255,234} },

    [9] = { {249,228,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {249,228,255}, {0,255,253}, {0,0,0}, {0,0,0}, {0,0,0}, {249,228,255}, {88,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,253}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {205,255,255}, {146,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {233,218,217}, {0,0,0}, {35,255,255}, {35,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {35,255,255}, {35,255,255}, {35,255,255}, {0,0,0}, {0,0,0}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {0,0,0}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {0,0,0}, {0,0,0}, {146,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {205,255,255}, {0,0,0}, {0,0,0}, {205,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
    case 8:
      set_layer_color(8);
      break;
    case 9:
      set_layer_color(9);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;


void custom_matrix_scan_user(void) {
    achordion_task();
}

// custom
LEADER_EXTERNS();
void matrix_scan_user(void) {
    custom_matrix_scan_user();
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();
        // Replace the sequences below with your own sequences.
        SEQ_ONE_KEY(KC_T) {
            // When I press KC_LEAD and then T, this sends CTRL + SHIFT + T
            SEND_STRING(SS_LCTRL(SS_LSFT("t")));
        }
        // Note: This is not an array, you don't need to put any commas
        // or semicolons between sequences.
        SEQ_TWO_KEYS(KC_S, KC_P) {
            tap_code(KC_PSCREEN);
        }
        SEQ_TWO_KEYS(KC_S, KC_B) {
            tap_code(KC_PAUSE);
        }
        SEQ_THREE_KEYS(KC_S, KC_B, KC_B) {
            register_code(KC_LCTRL);
            tap_code(KC_PAUSE);
            unregister_code(KC_LCTRL);
        }
        SEQ_THREE_KEYS(KC_S, KC_B, KC_B) {
            SEND_STRING(SS_LSFT(SS_TAP(X_PAUSE)));
        }
        SEQ_ONE_KEY(KC_Q) {
            SEND_STRING(SS_LALT(SS_TAP(X_F4)));
        }

        SEQ_THREE_KEYS(KC_A, KC_A, KC_A) {
            register_code(KC_RALT);
            register_code16(UK_2);
            unregister_code16(UK_2);
            unregister_code(KC_RALT);
            SEND_STRING(SS_LSFT("a"));
        }

        SEQ_TWO_KEYS(KC_A, KC_A) {
            register_code(KC_RALT);
            register_code16(UK_2);
            unregister_code16(UK_2);
            unregister_code(KC_RALT);
            tap_code(KC_A);
        }

        SEQ_THREE_KEYS(KC_A, KC_O, KC_O) {
            register_code(KC_RALT);
            register_code16(UK_2);
            unregister_code16(UK_2);
            unregister_code(KC_RALT);
            SEND_STRING(SS_LSFT("o"));
        }

        SEQ_TWO_KEYS(KC_A, KC_O) {
            register_code(KC_RALT);
            register_code16(UK_2);
            unregister_code16(UK_2);
            unregister_code(KC_RALT);
            tap_code(KC_O);
        }
        SEQ_THREE_KEYS(KC_A, KC_U, KC_U) {
            register_code(KC_RALT);
            register_code16(UK_2);
            unregister_code16(UK_2);
            unregister_code(KC_RALT);
            SEND_STRING(SS_LSFT("u"));
        }

        SEQ_TWO_KEYS(KC_A, KC_U) {
            register_code(KC_RALT);
            register_code16(UK_2);
            unregister_code16(UK_2);
            unregister_code(KC_RALT);
            tap_code(KC_U);
        }
  }
}

enum combos {
    WF_ESC,
    WF_ESC10,
    WF_ESC3,
    XC_BSPC,
    FP_Q,
    V_A,
    V_U,
    V_O,
    UY_ENTER,
    COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

// const uint16_t PROGMEM esc_combo[] = {MT(MOD_LGUI, KC_A), MT(MOD_LCTL, KC_T), COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_W, LT(4,KC_F), COMBO_END};
const uint16_t PROGMEM esc_combo10[] = {KC_F1, KC_F2, COMBO_END};
//const uint16_t PROGMEM esc_combo10[] = {KC_TAB, KC_F6, COMBO_END};
const uint16_t PROGMEM esc_combo3[] = {UK_BSLS, UK_LABK, COMBO_END};
//const uint16_t PROGMEM esc_combo3[] = {TD(DANCE_8), TD(DANCE_10), COMBO_END};
const uint16_t PROGMEM q_combo[] = {LT(4,KC_F),     LT(4,KC_P), COMBO_END};
const uint16_t PROGMEM auml_combo[] = {MT(MOD_LGUI, KC_A), KC_V, COMBO_END};
const uint16_t PROGMEM uuml_combo[] = {LT(3,KC_U), KC_V, COMBO_END};
const uint16_t PROGMEM ouml_combo[] = {MT(MOD_RGUI, KC_O), KC_V, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {LT(2,KC_X), LT(1,KC_C), COMBO_END};
const uint16_t PROGMEM enter_combo[] = {LT(3,KC_U), KC_Y, COMBO_END};


combo_t key_combos[] = {
    [WF_ESC] = COMBO(esc_combo, CUSTOM_ESC),
    [WF_ESC10] = COMBO(esc_combo10, CUSTOM_ESC),
    [WF_ESC3] = COMBO(esc_combo3, CUSTOM_ESC),
    [FP_Q] = COMBO(q_combo, CUSTOM_QU),
    [V_A] = COMBO(auml_combo, CUSTOM_AUML),
    [V_U] = COMBO(uuml_combo, CUSTOM_UUML),
    [V_O] = COMBO(ouml_combo, CUSTOM_OUML),
    [XC_BSPC] = COMBO(bspc_combo, CUSTOM_BSPACE),
    [UY_ENTER] = COMBO(enter_combo, CUSTOM_ENTER),
};
const key_override_t apo_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_QUOTE);
const key_override_t dash_key_override = ko_make_basic(MOD_MASK_SHIFT, LT(1,KC_COMMA), UK_MINS);
const key_override_t dquote_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_DQUO, UK_UNDS);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&apo_key_override,
	&dash_key_override,
    &dquote_key_override,
	NULL // Null terminate the array of overrides!
};
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LT(1,KC_C):
    case LT(1,KC_COMMA):
        // Immediately select the hold action when another key is pressed.
        return false;
    default:
        // Do not select the hold action when another key is pressed.
        return false;
    }
}
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MT(MOD_LSFT, KC_S):
    case MT(MOD_RSFT, KC_E):
    case LT(4,KC_F):
    case LT(4,KC_P):
    case LT(2,KC_Z):
    case LT(2,KC_X):
    case LT(1,KC_C):
    case LT(1,KC_D):
    case LT(1,KC_H):
    case LT(1,KC_COMMA):
        return true;
    default:
        return false;
    }
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    return 600;
}

bool achordion_eager_mod(uint8_t mod) {
    switch (mod) {
    case MOD_LSFT:
    case MOD_RSFT:
    case MOD_LCTL:
    case MOD_RCTL:
        return true;  // Eagerly apply Shift and Ctrl mods.

    default:
        return false;
    }
}

static bool custom_on_left_hand(keypos_t pos) {
    return pos.row < MATRIX_ROWS / 2;
}

bool custom_achordion_opposite_hands(const keyrecord_t* tap_hold_record,
                              const keyrecord_t* other_record) {
    return custom_on_left_hand(tap_hold_record->event.key)
        != custom_on_left_hand(other_record->event.key);
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
    uint16_t row = tap_hold_record->event.key.row;
    // holding key on thumb or buttom cow
    if (row == 5 || row == 6 || row == 11 || row == 12) return true;
    row = other_record->event.key.row;
    // other key on thumb
    if (row == 5 || row == 6 || row == 11 || row == 12) return true;
    return custom_achordion_opposite_hands(tap_hold_record, other_record);
}

bool send_grave_with_caps_word(uint16_t keycode, uint16_t mod_state) {
    bool is_caps_word = caps_word_get();
    del_mods(MOD_MASK_SHIFT);
    if (is_caps_word) {
        del_weak_mods(MOD_BIT(KC_LSFT));
    }
    register_code(KC_RALT);
    register_code16(UK_2);
    unregister_code16(UK_2);
    unregister_code(KC_RALT);
    set_mods(mod_state);
    if (is_caps_word) {
        register_weak_mods(MOD_BIT(KC_LSFT));
    }
    tap_code(keycode);
    return false;
}

bool custom_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) { return false; }
    if (!process_caps_word(keycode, record)) { return false; }
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
    uint8_t mod_state = get_mods();
    static bool is_shifted;
    is_shifted = get_mods() & MOD_MASK_SHIFT;
    if (record->event.pressed) {
        switch (keycode) {
        case CUSTOM_QU:
            if (is_shifted) {
                del_mods(MOD_MASK_SHIFT);
                SEND_STRING("Qu");
                set_mods(mod_state);
            } else {
                SEND_STRING("qu");
            }
            return false;
        case CUSTOM_AUML:
            return send_grave_with_caps_word(KC_A, mod_state);
        case CUSTOM_UUML:
            return send_grave_with_caps_word(KC_U, mod_state);
        case CUSTOM_OUML:
            return send_grave_with_caps_word(KC_O, mod_state);
        case CUSTOM_BSPACE:
            tap_code(KC_BSPACE);
            return false;
        case CUSTOM_ENTER:
            tap_code(KC_ENTER);
            return false;
        case CUSTOM_ESC:
            uint8_t layer = biton32(layer_state);
            if (layer > 0) {
                layer_move(0);
            } else {
                tap_code16(KC_ESC);
            }
            return false;
        }
    }
    return true;
}

__attribute__((weak)) bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
    case CUSTOM_QU ... CUSTOM_END_CAPS:
        register_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to the next key.
        return true;

        // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_MINS:
    case KC_UNDS:
        return true;

    default:
        return false;  // Deactivate Caps Word.
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!custom_record_user(keycode, record)) { return false; }
    switch (keycode) {
    case ST_MACRO_0:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_SPACE));

        }
        break;
    case RGB_SLD:
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
    }
    return true;
}
