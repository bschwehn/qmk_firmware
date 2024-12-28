// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H
#include "keymap_custom.h"
#include "keymap_uk.h"

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
#define KC_BSPACE KC_BSPC
#define KC_RSHIFT KC_RSFT
#define KC_NA KC_TRANSPARENT
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
//#define AL_BSPC MT(MOD_LCTL, KC_BSPC)
#define AL_BSPC LT(LR_EXTRAS, KC_BSPC)
//#define AL_THMB3 MT(MOD_LSFT, KC_ENT)
#define AL_THMB3 TD(DANCE_12)
#define HRM_A MT(MOD_LGUI, KC_A)
#define HRM_R MT(MOD_LALT, KC_R)
#define HRM_S MT(MOD_LSFT, KC_S)
#define HRM_T MT(MOD_LCTL, KC_T)
#define HRM_N MT(MOD_RCTL, KC_N)
#define HRM_E MT(MOD_RSFT, KC_E)
#define HRM_I MT(MOD_LALT, KC_I)
#define HRM_O MT(MOD_RGUI, KC_O)
#define LT_COMMA LT(1, KC_COMMA)
#define LT_H LT(1, KC_H)
#define LT_X LT(2, KC_X)
#define LT_C LT(1, KC_C)
#define LT_Z LT(2, KC_Z)
#define LT_D LT(1, KC_D)
#define LT_F LT(4, KC_F)
#define LT_P LT(4, KC_P)
#define LT_L LT(3, KC_L)
#define LT_U LT(3, KC_U)

#define LT_DQUO CUSTOM_PT_DQUO

#include "g/keymap_combo.h"

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

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

  [LR_BASE] = LAYOUT_split_3x6_3(
        KC_TAB,         KC_Q,           KC_W,           LT_F,     LT_P,     KC_B,
        KC_J, LT_L, LT_U, KC_Y, UK_COLN, KC_APPLICATION,

    LT(5,KC_ESCAPE), HRM_A, HRM_R, HRM_S, HRM_T, KC_G,
        KC_M, HRM_N, HRM_E, HRM_I, HRM_O, QK_ALT_REPEAT_KEY,

    LLOCK,        LT_Z,     LT_X,     LT_C,     LT_D,     KC_V,
    KC_K,           LT_H,     LT_COMMA, KC_DOT,         UK_DQUO,        TT(LR_POINTER),

    MT(MOD_LCTL, KC_DELETE),  KC_SPACE, AL_THMB3,
    QK_LEAD, AL_BSPC, QK_REPEAT_KEY
  ),
  [LR_BRACES] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, KC_TRANSPARENT, UK_BSLS,        UK_LABK,        UK_RABK,        UK_PERC,
    UK_AT,          UK_QUES,        UK_PIPE,        UK_ASTR,        UK_GRV,         KC_PSCR,

    TO(0),          UK_COLN,    UK_SCLN, UK_LCBR,    UK_RCBR,    UK_PLUS,
    UK_CIRC,        UK_EQL,     UK_AMPR,    UK_DLR,   UK_MINS,  KC_TRANSPARENT,

    KC_TRANSPARENT, UK_LPRN,        UK_RPRN,        UK_LBRC,        UK_RBRC,        UK_MINS,
    UK_TILD,        UK_EXLM,        UK_UNDS,        UK_SLSH,        UK_HASH,        KC_RALT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, QK_ALT_REPEAT_KEY ),
  [LR_NAV] = LAYOUT_split_3x6_3(
    KC_SYSTEM_SLEEP, KC_MS_WH_DOWN,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP, KC_MS_RIGHT,
        KC_DOWN, KC_RIGHT,     LSFT(KC_INSERT), LCTL(KC_INSERT), LSFT(KC_DELETE), KC_VOLU,

    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_ACCEL1,
    KC_HOME,        KC_PGDN,        KC_PGUP,          KC_END,       KC_PAUSE,       KC_MUTE,

    QK_BOOT, KC_PC_UNDO,     KC_PC_CUT,      KC_PC_COPY,     KC_PC_PASTE,    KC_MS_ACCEL2,
    KC_UP, KC_LEFT,  KC_APP,    KC_SCRL,        KC_INSERT,         KC_VOLD,

    KC_MS_WH_UP,    KC_MS_WH_DOWN,  KC_TRANSPARENT,
    KC_TRANSPARENT, LCTL(KC_MS_WH_DOWN),LCTL(KC_MS_WH_UP)
  ),
  [LR_FUN] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, LSFT(KC_TAB),   KC_F1,          KC_F2,          KC_F3,          KC_F10,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TAB,         KC_F4,          KC_F5,          KC_F6,          KC_F11,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_APPLICATION, KC_F7,          KC_F8,          KC_F9,          KC_F12,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [LR_NUM] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    UK_0,           UK_1,           UK_2,           UK_3,           TD(DANCE_11),   KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_KP_MINUS,    UK_4,           UK_5,           UK_6,           KC_KP_DOT,      KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_KP_PLUS, UK_7,        UK_8,           UK_9,           KC_KP_COMMA,    KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  /* note: accell has no effect in kinetic or accellerated mode */
  [LR_POINTER] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN3, KC_MS_BTN1, KC_MS_BTN2,  KC_MS_ACCEL0,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_MS_ACCEL1,
    KC_TRANSPARENT, KC_MS_BTN1, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, KC_MS_ACCEL2,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_ACCEL0, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [LR_EXTRAS] = LAYOUT_split_3x6_3
    // note: MT from base works if pressed earlier, MT not working with custom keys
    (
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, CUSTOM_UUML, KC_NO, KC_NO, KC_NO,

     KC_NO, CUSTOM_AUML, KC_LALT, KC_LSFT, KC_LCTL, KC_NO,
     KC_NO, CUSTOM_DARROW, KC_LSFT, KC_LALT, CUSTOM_OUML, KC_NO,

    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, CUSTOM_HTTPS, CUSTOM_ARROW, KC_NO, CUSTOM_EMPROP, KC_NO,

    KC_NO, KC_ENT, KC_NO,
    KC_NO, KC_NO, KC_NO
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
if (!custom_record_user(keycode, record)) { return false; }
  switch (keycode) {
    case MC_0:
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

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
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


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_LCBR);
        tap_code16(UK_LCBR);
        tap_code16(UK_LCBR);
    }
    if(state->count > 3) {
        tap_code16(UK_LCBR);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(UK_LCBR); break;
        case SINGLE_HOLD: register_code16(UK_RCBR); break;
        case DOUBLE_TAP: register_code16(UK_LCBR); register_code16(UK_LCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_LCBR); register_code16(UK_LCBR);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(UK_LCBR); break;
        case SINGLE_HOLD: unregister_code16(UK_RCBR); break;
        case DOUBLE_TAP: unregister_code16(UK_LCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_LCBR); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_LBRC);
        tap_code16(UK_LBRC);
        tap_code16(UK_LBRC);
    }
    if(state->count > 3) {
        tap_code16(UK_LBRC);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(UK_LBRC); break;
        case SINGLE_HOLD: register_code16(UK_RBRC); break;
        case DOUBLE_TAP: register_code16(UK_LBRC); register_code16(UK_LBRC); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_LBRC); register_code16(UK_LBRC);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(UK_LBRC); break;
        case SINGLE_HOLD: unregister_code16(UK_RBRC); break;
        case DOUBLE_TAP: unregister_code16(UK_LBRC); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_LBRC); break;
    }
    dance_state[1].step = 0;
}
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: layer_move(5); break;
        case DOUBLE_TAP: layer_move(9); break;
        case DOUBLE_SINGLE_TAP: layer_move(5); break;
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
    }
    dance_state[2].step = 0;
}
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: layer_move(2); break;
        case DOUBLE_TAP: layer_move(6); break;
        case DOUBLE_SINGLE_TAP: layer_move(2); break;
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
    }
    dance_state[3].step = 0;
}
void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
    }
    if(state->count > 3) {
        tap_code16(KC_QUOTE);
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_QUOTE); break;
        case SINGLE_HOLD: register_code16(UK_MINS); break;
        case DOUBLE_TAP: register_code16(KC_QUOTE); register_code16(KC_QUOTE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_QUOTE); register_code16(KC_QUOTE);
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_QUOTE); break;
        case SINGLE_HOLD: unregister_code16(UK_MINS); break;
        case DOUBLE_TAP: unregister_code16(KC_QUOTE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_QUOTE); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_DQUO);
        tap_code16(UK_DQUO);
        tap_code16(UK_DQUO);
    }
    if(state->count > 3) {
        tap_code16(UK_DQUO);
    }
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(UK_DQUO); break;
        case SINGLE_HOLD: register_code16(UK_GRV); break;
        case DOUBLE_TAP: register_code16(UK_DQUO); register_code16(UK_DQUO); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_DQUO); register_code16(UK_DQUO);
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(UK_DQUO); break;
        case SINGLE_HOLD: unregister_code16(UK_GRV); break;
        case DOUBLE_TAP: unregister_code16(UK_DQUO); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_DQUO); break;
    }
    dance_state[5].step = 0;
}
void on_dance_6(tap_dance_state_t *state, void *user_data);
void dance_6_finished(tap_dance_state_t *state, void *user_data);
void dance_6_reset(tap_dance_state_t *state, void *user_data);

void on_dance_6(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_COLN);
        tap_code16(UK_COLN);
        tap_code16(UK_COLN);
    }
    if(state->count > 3) {
        tap_code16(UK_COLN);
    }
}

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(UK_COLN); break;
        case SINGLE_HOLD: register_code16(KC_LGUI); break;
        case DOUBLE_TAP: register_code16(UK_COLN); register_code16(UK_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_COLN); register_code16(UK_COLN);
    }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(UK_COLN); break;
        case SINGLE_HOLD: unregister_code16(KC_LGUI); break;
        case DOUBLE_TAP: unregister_code16(UK_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_COLN); break;
    }
    dance_state[6].step = 0;
}
void on_dance_7(tap_dance_state_t *state, void *user_data);
void dance_7_finished(tap_dance_state_t *state, void *user_data);
void dance_7_reset(tap_dance_state_t *state, void *user_data);

void on_dance_7(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_LCBR);
        tap_code16(UK_LCBR);
        tap_code16(UK_LCBR);
    }
    if(state->count > 3) {
        tap_code16(UK_LCBR);
    }
}

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(UK_LCBR); break;
        case SINGLE_HOLD: register_code16(KC_LSFT); break;
        case DOUBLE_TAP: register_code16(UK_LCBR); register_code16(UK_LCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_LCBR); register_code16(UK_LCBR);
    }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(UK_LCBR); break;
        case SINGLE_HOLD: unregister_code16(KC_LSFT); break;
        case DOUBLE_TAP: unregister_code16(UK_LCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_LCBR); break;
    }
    dance_state[7].step = 0;
}
void on_dance_8(tap_dance_state_t *state, void *user_data);
void dance_8_finished(tap_dance_state_t *state, void *user_data);
void dance_8_reset(tap_dance_state_t *state, void *user_data);

void on_dance_8(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_RCBR);
        tap_code16(UK_RCBR);
        tap_code16(UK_RCBR);
    }
    if(state->count > 3) {
        tap_code16(UK_RCBR);
    }
}

void dance_8_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(UK_RCBR); break;
        case SINGLE_HOLD: register_code16(KC_LCTL); break;
        case DOUBLE_TAP: register_code16(UK_RCBR); register_code16(UK_RCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_RCBR); register_code16(UK_RCBR);
    }
}

void dance_8_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(UK_RCBR); break;
        case SINGLE_HOLD: unregister_code16(KC_LCTL); break;
        case DOUBLE_TAP: unregister_code16(UK_RCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_RCBR); break;
    }
    dance_state[8].step = 0;
}
void on_dance_9(tap_dance_state_t *state, void *user_data);
void dance_9_finished(tap_dance_state_t *state, void *user_data);
void dance_9_reset(tap_dance_state_t *state, void *user_data);

void on_dance_9(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_AMPR);
        tap_code16(UK_AMPR);
        tap_code16(UK_AMPR);
    }
    if(state->count > 3) {
        tap_code16(UK_AMPR);
    }
}

void dance_9_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(UK_AMPR); break;
        case SINGLE_HOLD: register_code16(KC_RSFT); break;
        case DOUBLE_TAP: register_code16(UK_AMPR); register_code16(UK_AMPR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_AMPR); register_code16(UK_AMPR);
    }
}

void dance_9_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(UK_AMPR); break;
        case SINGLE_HOLD: unregister_code16(KC_RSFT); break;
        case DOUBLE_TAP: unregister_code16(UK_AMPR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_AMPR); break;
    }
    dance_state[9].step = 0;
}
void on_dance_10(tap_dance_state_t *state, void *user_data);
void dance_10_finished(tap_dance_state_t *state, void *user_data);
void dance_10_reset(tap_dance_state_t *state, void *user_data);

void on_dance_10(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_DLR);
        tap_code16(UK_DLR);
        tap_code16(UK_DLR);
    }
    if(state->count > 3) {
        tap_code16(UK_DLR);
    }
}

void dance_10_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: register_code16(UK_DLR); break;
        case SINGLE_HOLD: register_code16(KC_LALT); break;
        case DOUBLE_TAP: register_code16(UK_DLR); register_code16(UK_DLR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_DLR); register_code16(UK_DLR);
    }
}

void dance_10_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP: unregister_code16(UK_DLR); break;
        case SINGLE_HOLD: unregister_code16(KC_LALT); break;
        case DOUBLE_TAP: unregister_code16(UK_DLR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_DLR); break;
    }
    dance_state[10].step = 0;
}
void on_dance_11(tap_dance_state_t *state, void *user_data);
void dance_11_finished(tap_dance_state_t *state, void *user_data);
void dance_11_reset(tap_dance_state_t *state, void *user_data);

void on_dance_11(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_ASTERISK);
        tap_code16(KC_KP_ASTERISK);
        tap_code16(KC_KP_ASTERISK);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_ASTERISK);
    }
}

void dance_11_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(KC_KP_ASTERISK); break;
        case SINGLE_HOLD: register_code16(KC_KP_SLASH); break;
        case DOUBLE_TAP: register_code16(KC_KP_ASTERISK); register_code16(KC_KP_ASTERISK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_ASTERISK); register_code16(KC_KP_ASTERISK);
    }
}

void dance_11_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_ASTERISK); break;
        case SINGLE_HOLD: unregister_code16(KC_KP_SLASH); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_ASTERISK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_ASTERISK); break;
    }
    dance_state[11].step = 0;
}
void on_dance_12(tap_dance_state_t *state, void *user_data);
void dance_12_finished(tap_dance_state_t *state, void *user_data);
void dance_12_reset(tap_dance_state_t *state, void *user_data);

void on_dance_12(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SPC);
        tap_code16(KC_SPC);
        tap_code16(KC_SPC);
    }
    if(state->count > 3) {
        tap_code16(KC_SPC);
    }
}

void dance_12_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(KC_SPC); break;
        case SINGLE_HOLD: register_code16(KC_LSFT); break;
        case DOUBLE_TAP: register_code16(KC_ENT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SPC); register_code16(KC_SPC);
    }
}

void dance_12_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(KC_SPC); break;
        case SINGLE_HOLD: unregister_code16(KC_LSFT); break;
        case DOUBLE_TAP: unregister_code16(KC_ENT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SPC); break;
    }
    dance_state[12].step = 0;

}

tap_dance_action_t tap_dance_actions[] = {
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
#ifdef LEADER_ENABLE
void leader_end_user(void) {
    if (leader_sequence_one_key(KC_BSPC)) {
        tap_code(KC_BSPC);
    }
    else if (leader_sequence_one_key(KC_A)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("1"))));
    }
    else if  (leader_sequence_one_key(KC_R)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("2"))));
    }
    else if  (leader_sequence_one_key(KC_S)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("3"))));
    }
    else if  (leader_sequence_one_key(KC_T)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("4"))));
    }
    else if  (leader_sequence_one_key(KC_G)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("5"))));
    }
    else if  (leader_sequence_one_key(KC_M)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("6"))));
    }
    else if  (leader_sequence_one_key(KC_N)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("7"))));
    }
    else if  (leader_sequence_one_key(KC_E)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("8"))));
    }
    else if  (leader_sequence_one_key(KC_I)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("9"))));
    }
    else if  (leader_sequence_one_key(KC_O)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("0"))));
    }
    else if  (leader_sequence_two_keys(KC_A, KC_A)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("a"))));
    }
    else if (leader_sequence_two_keys(KC_R, KC_R)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("r"))));
    }
    else if (leader_sequence_two_keys(KC_S, KC_S)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("s"))));
    }
    else if (leader_sequence_two_keys(KC_T, KC_T)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("t"))));
    }
    else if (leader_sequence_two_keys(KC_G, KC_G)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("g"))));
    }
    else if (leader_sequence_two_keys(KC_M, KC_M)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("m"))));
    }
    else if (leader_sequence_two_keys(KC_N, KC_N)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("n"))));
    }
    else if (leader_sequence_two_keys(KC_E, KC_E)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("e"))));
    }
    else if (leader_sequence_two_keys(KC_I, KC_I)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("i"))));
    }
    else if (leader_sequence_two_keys(KC_O, KC_O)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("o"))));
    }
    else if (leader_sequence_two_keys(KC_S, KC_R)) {
        tap_code(KC_SCROLL_LOCK);
    }
    else if (leader_sequence_two_keys(KC_S, KC_P)) {
        tap_code(KC_PSCR);
    }
    else if (leader_sequence_two_keys(KC_S, KC_I)) {
        tap_code(KC_INSERT);
    }
    else if (leader_sequence_two_keys(KC_S, KC_H)) {
        tap_code(KC_HOME);
    }
    else if (leader_sequence_two_keys(KC_S, KC_E)) {
        tap_code(KC_END);
    }
    else if (leader_sequence_two_keys(KC_S, KC_U)) {
        tap_code(KC_PAGE_UP);
    }
    else if (leader_sequence_two_keys(KC_S, KC_D)) {
        tap_code(KC_PAGE_DOWN);
    }
    else if (leader_sequence_two_keys(KC_S, KC_N)) {
        tap_code(KC_NUM_LOCK);
    }
    else if (leader_sequence_two_keys(KC_S, KC_C)) {
        tap_code(KC_CAPS_LOCK);
    }
    else if (leader_sequence_two_keys(KC_S, KC_A)) {
        tap_code(KC_APPLICATION);
    }
    else if (leader_sequence_two_keys(KC_S, KC_B)) {
        tap_code(KC_PAUSE);
    }
    else if (leader_sequence_three_keys(KC_S, KC_B, KC_B)) {
        register_code(KC_LCTL);
        tap_code(KC_PAUSE);
        unregister_code(KC_LCTL);
    }
    else if (leader_sequence_two_keys(KC_Q, KC_Q)) {
        SEND_STRING(SS_LALT(SS_TAP(X_F4)));
    }
    // note: need to press leader while in braces layer already
    else if (leader_sequence_one_key(UK_QUES)) {
        SEND_STRING("Home row single: Gui+C+Alt+ 1-0\n "
                    "Home row double: Gui+C+Alt+letter\n"
                    "S,R: scroll lock\n "
                    "S,P: print screen\n "
                    "S,H: home\n "
                    "S,E: end\n "
                    "S,I: insert\n "
                    "S,U: page up\n "
                    "S,D: page down\n "
                    "S,N: num lock\n "
                    "S,C: caps lock\n "
                    "S,H: home\n "
                    "Q,Q: Alt+F4\n "
                    "?: help\n "
                    "S,B: Break\n "
                    "S,B,B: C+Break\n");
    }
    // does not seem to work actually
    else if (leader_sequence_four_keys(KC_B, KC_O, KC_O, KC_T)) {
        tap_code16(QK_BOOT);
    }
}
#endif

const key_override_t apo_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_QUOTE);
const key_override_t dash_key_override = ko_make_basic(MOD_MASK_SHIFT, LT(LR_BRACES,KC_COMMA), UK_MINS);
const key_override_t dquote_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_DQUO, UK_UNDS);
const key_override_t coln_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_COLN, UK_SCLN);
//const key_override_t coln_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_COLN, UK_UNDS);

const key_override_t **key_overrides = (const key_override_t *[]){
    &apo_key_override,
    &dash_key_override,
    &dquote_key_override,
    &coln_key_override,
    NULL // Null terminate the array of overrides!
};


#ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
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
#endif
