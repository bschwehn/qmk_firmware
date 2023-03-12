// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H
#include "keymap_custom.h"
#include "keymap_uk.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)

enum tap_dance_codes {
    DANCE_0,
    DANCE_1,
    DANCE_2,
    DANCE_3,
    DANCE_4,
    DANCE_5,
    DANCE_6,
    DANCE_7,
    DANCE_8,
    DANCE_9,
    DANCE_10,
    DANCE_11,
    DANCE_12,
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Alt│
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤Bsp│   │Ent├───┘
      *                       └───┘   └───┘
      */
    /* [0] = LAYOUT_split_3x6_3( */
    /*     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, */
    /*     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, */
    /*     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, */
    /*                                         KC_LGUI, KC_SPC, KC_BSPC,          KC_ENT, KC_SPC, KC_RALT */
    /* ) */

  [0] = LAYOUT_split_3x6_3(
                           KC_TAB,         KC_Q,           KC_W,           LT(4,KC_F),     LT(4,KC_P),     KC_B,           KC_J, LT(3,KC_L), LT(3,KC_U), KC_Y, TD(DANCE_4), KC_TRANSPARENT,
    LT(5,KC_ESCAPE), MT(MOD_LGUI, KC_A),MT(MOD_LALT, KC_R),MT(MOD_LSFT, KC_S),MT(MOD_LCTL, KC_T),KC_G,   KC_M,  MT(MOD_RCTL, KC_N),MT(MOD_RSFT, KC_E),MT(MOD_LALT, KC_I),MT(MOD_RGUI, KC_O),KC_APPLICATION,
    LLOCK,        LT(2,KC_Z),     LT(2,KC_X),     LT(1,KC_C),     LT(1,KC_D),     KC_V,                                           KC_K,           LT(1,KC_H),     LT(1,KC_COMMA), KC_DOT,         UK_DQUO,        KC_RSPC,
                           MT(MOD_LCTL, KC_DELETE),  KC_SPACE, MT(MOD_LSFT, KC_ENTER),                MT(MOD_RSFT, KC_ENTER),MT(MOD_LCTL, KC_BSPACE),KC_LEAD
  ),
  [1] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, KC_TRANSPARENT, UK_BSLS,        UK_LABK,        UK_RABK,        UK_PERC,      UK_AT,          UK_QUES,        UK_PIPE,        UK_ASTR,        UK_GRV,         KC_PSCREEN,
    TO(0),          TD(DANCE_6),    MT(MOD_LALT, UK_SCLN),TD(DANCE_7),    TD(DANCE_8),    UK_PLUS,         UK_CIRC,     MT(MOD_RCTL, UK_EQL),TD(DANCE_9),    TD(DANCE_10),   MT(MOD_RGUI, UK_MINS),KC_TRANSPARENT,
    KC_TRANSPARENT, UK_LPRN,        UK_RPRN,        UK_LBRC,        UK_RBRC,        UK_MINS,                                        UK_TILD,        UK_EXLM,        UK_UNDS,        UK_SLSH,        UK_HASH,        KC_RALT,
    KC_SPACE,       UK_SCLN,        UK_COLN,                        UK_UNDS,        KC_LPRN,        KC_ENTER
  ),
  [2] = LAYOUT_split_3x6_3(
                           KC_SYSTEM_SLEEP, KC_MS_WH_DOWN,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_ACCEL0,    LCTL(KC_Z),     LSFT(KC_INSERT),LCTL(KC_INSERT),LSFT(KC_DELETE),LCTL(KC_Y),     KC_PSCREEN,
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_ACCEL1,    KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_PAUSE,       KC_TRANSPARENT,
                           RESET, KC_PC_UNDO,     KC_PC_CUT,      KC_PC_COPY,     KC_PC_PASTE,    KC_MS_ACCEL2,   KC_HOME,  KC_PGDN,    KC_PGUP,        KC_END,         KC_INSERT,      KC_TRANSPARENT,
    KC_MS_WH_UP,    KC_MS_WH_DOWN,  KC_TRANSPARENT,                 KC_TRANSPARENT, LCTL(KC_MS_WH_DOWN),LCTL(KC_MS_WH_UP)
  ),
  [3] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, LSFT(KC_TAB),   KC_F1,          KC_F2,          KC_F3,          KC_F10,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TAB,         KC_F4,          KC_F5,          KC_F6,          KC_F11,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_APPLICATION, KC_F7,          KC_F8,          KC_F9,          KC_F12,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,    UK_0,           UK_1,           UK_2,           UK_3,           TD(DANCE_11),   KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_KP_MINUS,    UK_4,           UK_5,           UK_6,           KC_KP_DOT,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,    KC_KP_PLUS, UK_7,        UK_8,           UK_9,           KC_KP_COMMA,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, LSFT(KC_TAB),   KC_F1,          KC_F2,          KC_F3,          KC_F10,          UK_0,           UK_1,           UK_2,           UK_3,           TD(DANCE_12),   KC_TRANSPARENT,
    TO(0),          KC_TAB,         KC_F4,          KC_F5,          KC_F6,          KC_F11,          KC_KP_MINUS,    UK_4,           UK_5,           UK_6,           KC_KP_DOT,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_APPLICATION, KC_F7,          KC_F8,          KC_F9,          KC_F12,                                         KC_KP_PLUS,     UK_7,           UK_8,           UK_9,           KC_KP_COMMA,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,            KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_A,           KC_S,           KC_D,           KC_F,           KC_G,            KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,    KC_N, KC_M,                  KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [7] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_KP_PLUS,     KC_TRANSPARENT,
    TO(0),          KC_LGUI,        KC_LALT,        KC_LSHIFT,      KC_LCTRL,       KC_TRANSPARENT,  KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_KP_MINUS,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,            KC_2,           KC_3,           KC_EQUAL,       KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [8] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT,
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                  KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_TRANSPARENT, KC_TRANSPARENT,
    KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,          KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [9] = LAYOUT_split_3x6_3(
                           DYN_REC_STOP,   DYN_REC_START1, DYN_MACRO_PLAY1,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT, RGB_HUI,        RGB_HUD,        RGB_MOD,        KC_TRANSPARENT,        KC_TRANSPARENT,
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  AU_TOG,         RGB_VAI,        RGB_VAD,        KC_TRANSPARENT, RGB_TOG,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         RGB_SAD,        KC_TRANSPARENT,KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [10] = LAYOUT_split_3x6_3(
    LSFT(KC_TAB),   LSFT(KC_Q),     LSFT(UK_W),     LSFT(UK_F),     LSFT(KC_P),     LSFT(UK_B),             LSFT(KC_J),     LSFT(KC_L),     LSFT(KC_U),     LSFT(KC_Y),     UK_AT,          KC_TRANSPARENT,
    KC_TRANSPARENT, LSFT(KC_A),     LSFT(KC_R),     LSFT(KC_S),     LSFT(KC_T),     LSFT(KC_G),             LSFT(KC_M),     LSFT(KC_N),     LSFT(KC_E),     LSFT(KC_I),     LSFT(KC_O),     KC_TRANSPARENT,
    KC_TRANSPARENT, LSFT(KC_Z),     LSFT(KC_X),     LSFT(KC_C),     LSFT(KC_D),     LSFT(KC_V),          UK_LABK,        UK_RABK,        UK_QUES,        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
if (!custom_record_user(keycode, record)) { return false; }
  switch (keycode) {
    case MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_SPACE));

    }
    break;
  }
  return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[13];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_LCBR);
        tap_code16(UK_LCBR);
        tap_code16(UK_LCBR);
    }
    if(state->count > 3) {
        tap_code16(UK_LCBR);
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(UK_LCBR); break;
        case SINGLE_HOLD: register_code16(UK_RCBR); break;
        case DOUBLE_TAP: register_code16(UK_LCBR); register_code16(UK_LCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_LCBR); register_code16(UK_LCBR);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(UK_LCBR); break;
        case SINGLE_HOLD: unregister_code16(UK_RCBR); break;
        case DOUBLE_TAP: unregister_code16(UK_LCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_LCBR); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_LBRC);
        tap_code16(UK_LBRC);
        tap_code16(UK_LBRC);
    }
    if(state->count > 3) {
        tap_code16(UK_LBRC);
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(UK_LBRC); break;
        case SINGLE_HOLD: register_code16(UK_RBRC); break;
        case DOUBLE_TAP: register_code16(UK_LBRC); register_code16(UK_LBRC); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_LBRC); register_code16(UK_LBRC);
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(UK_LBRC); break;
        case SINGLE_HOLD: unregister_code16(UK_RBRC); break;
        case DOUBLE_TAP: unregister_code16(UK_LBRC); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_LBRC); break;
    }
    dance_state[1].step = 0;
}
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: layer_move(5); break;
        case DOUBLE_TAP: layer_move(9); break;
        case DOUBLE_SINGLE_TAP: layer_move(5); break;
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
    }
    dance_state[2].step = 0;
}
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: layer_move(2); break;
        case DOUBLE_TAP: layer_move(6); break;
        case DOUBLE_SINGLE_TAP: layer_move(2); break;
    }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
    }
    dance_state[3].step = 0;
}
void on_dance_4(qk_tap_dance_state_t *state, void *user_data);
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_4(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
    }
    if(state->count > 3) {
        tap_code16(KC_QUOTE);
    }
}

void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_QUOTE); break;
        case SINGLE_HOLD: register_code16(UK_MINS); break;
        case DOUBLE_TAP: register_code16(KC_QUOTE); register_code16(KC_QUOTE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_QUOTE); register_code16(KC_QUOTE);
    }
}

void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_QUOTE); break;
        case SINGLE_HOLD: unregister_code16(UK_MINS); break;
        case DOUBLE_TAP: unregister_code16(KC_QUOTE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_QUOTE); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(qk_tap_dance_state_t *state, void *user_data);
void dance_5_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_5_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_5(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_DQUO);
        tap_code16(UK_DQUO);
        tap_code16(UK_DQUO);
    }
    if(state->count > 3) {
        tap_code16(UK_DQUO);
    }
}

void dance_5_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(UK_DQUO); break;
        case SINGLE_HOLD: register_code16(UK_GRV); break;
        case DOUBLE_TAP: register_code16(UK_DQUO); register_code16(UK_DQUO); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_DQUO); register_code16(UK_DQUO);
    }
}

void dance_5_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(UK_DQUO); break;
        case SINGLE_HOLD: unregister_code16(UK_GRV); break;
        case DOUBLE_TAP: unregister_code16(UK_DQUO); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_DQUO); break;
    }
    dance_state[5].step = 0;
}
void on_dance_6(qk_tap_dance_state_t *state, void *user_data);
void dance_6_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_6_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_6(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_COLN);
        tap_code16(UK_COLN);
        tap_code16(UK_COLN);
    }
    if(state->count > 3) {
        tap_code16(UK_COLN);
    }
}

void dance_6_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(UK_COLN); break;
        case SINGLE_HOLD: register_code16(KC_LGUI); break;
        case DOUBLE_TAP: register_code16(UK_COLN); register_code16(UK_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_COLN); register_code16(UK_COLN);
    }
}

void dance_6_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(UK_COLN); break;
        case SINGLE_HOLD: unregister_code16(KC_LGUI); break;
        case DOUBLE_TAP: unregister_code16(UK_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_COLN); break;
    }
    dance_state[6].step = 0;
}
void on_dance_7(qk_tap_dance_state_t *state, void *user_data);
void dance_7_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_7_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_7(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_LCBR);
        tap_code16(UK_LCBR);
        tap_code16(UK_LCBR);
    }
    if(state->count > 3) {
        tap_code16(UK_LCBR);
    }
}

void dance_7_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(UK_LCBR); break;
        case SINGLE_HOLD: register_code16(KC_LSHIFT); break;
        case DOUBLE_TAP: register_code16(UK_LCBR); register_code16(UK_LCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_LCBR); register_code16(UK_LCBR);
    }
}

void dance_7_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(UK_LCBR); break;
        case SINGLE_HOLD: unregister_code16(KC_LSHIFT); break;
        case DOUBLE_TAP: unregister_code16(UK_LCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_LCBR); break;
    }
    dance_state[7].step = 0;
}
void on_dance_8(qk_tap_dance_state_t *state, void *user_data);
void dance_8_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_8_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_8(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_RCBR);
        tap_code16(UK_RCBR);
        tap_code16(UK_RCBR);
    }
    if(state->count > 3) {
        tap_code16(UK_RCBR);
    }
}

void dance_8_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(UK_RCBR); break;
        case SINGLE_HOLD: register_code16(KC_LCTRL); break;
        case DOUBLE_TAP: register_code16(UK_RCBR); register_code16(UK_RCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_RCBR); register_code16(UK_RCBR);
    }
}

void dance_8_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(UK_RCBR); break;
        case SINGLE_HOLD: unregister_code16(KC_LCTRL); break;
        case DOUBLE_TAP: unregister_code16(UK_RCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_RCBR); break;
    }
    dance_state[8].step = 0;
}
void on_dance_9(qk_tap_dance_state_t *state, void *user_data);
void dance_9_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_9_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_9(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_AMPR);
        tap_code16(UK_AMPR);
        tap_code16(UK_AMPR);
    }
    if(state->count > 3) {
        tap_code16(UK_AMPR);
    }
}

void dance_9_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(UK_AMPR); break;
        case SINGLE_HOLD: register_code16(KC_RSHIFT); break;
        case DOUBLE_TAP: register_code16(UK_AMPR); register_code16(UK_AMPR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_AMPR); register_code16(UK_AMPR);
    }
}

void dance_9_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(UK_AMPR); break;
        case SINGLE_HOLD: unregister_code16(KC_RSHIFT); break;
        case DOUBLE_TAP: unregister_code16(UK_AMPR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_AMPR); break;
    }
    dance_state[9].step = 0;
}
void on_dance_10(qk_tap_dance_state_t *state, void *user_data);
void dance_10_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_10_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_10(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_DLR);
        tap_code16(UK_DLR);
        tap_code16(UK_DLR);
    }
    if(state->count > 3) {
        tap_code16(UK_DLR);
    }
}

void dance_10_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: register_code16(UK_DLR); break;
        case SINGLE_HOLD: register_code16(KC_LALT); break;
        case DOUBLE_TAP: register_code16(UK_DLR); register_code16(UK_DLR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_DLR); register_code16(UK_DLR);
    }
}

void dance_10_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP: unregister_code16(UK_DLR); break;
        case SINGLE_HOLD: unregister_code16(KC_LALT); break;
        case DOUBLE_TAP: unregister_code16(UK_DLR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_DLR); break;
    }
    dance_state[10].step = 0;
}
void on_dance_11(qk_tap_dance_state_t *state, void *user_data);
void dance_11_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_11_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_11(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_ASTERISK);
        tap_code16(KC_KP_ASTERISK);
        tap_code16(KC_KP_ASTERISK);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_ASTERISK);
    }
}

void dance_11_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(KC_KP_ASTERISK); break;
        case SINGLE_HOLD: register_code16(KC_KP_SLASH); break;
        case DOUBLE_TAP: register_code16(KC_KP_ASTERISK); register_code16(KC_KP_ASTERISK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_ASTERISK); register_code16(KC_KP_ASTERISK);
    }
}

void dance_11_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_ASTERISK); break;
        case SINGLE_HOLD: unregister_code16(KC_KP_SLASH); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_ASTERISK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_ASTERISK); break;
    }
    dance_state[11].step = 0;
}
void on_dance_12(qk_tap_dance_state_t *state, void *user_data);
void dance_12_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_12_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_12(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_ASTERISK);
        tap_code16(KC_KP_ASTERISK);
        tap_code16(KC_KP_ASTERISK);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_ASTERISK);
    }
}

void dance_12_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(KC_KP_ASTERISK); break;
        case SINGLE_HOLD: register_code16(KC_KP_SLASH); break;
        case DOUBLE_TAP: register_code16(KC_KP_ASTERISK); register_code16(KC_KP_ASTERISK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_ASTERISK); register_code16(KC_KP_ASTERISK);
    }
}

void dance_12_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_ASTERISK); break;
        case SINGLE_HOLD: unregister_code16(KC_KP_SLASH); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_ASTERISK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_ASTERISK); break;
    }
    dance_state[12].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
        [DANCE_10] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
        [DANCE_11] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_11, dance_11_finished, dance_11_reset),
        [DANCE_12] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset),
};

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
        SEQ_ONE_KEY(TD(DANCE_1)) {
            SEND_STRING("` ");
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
