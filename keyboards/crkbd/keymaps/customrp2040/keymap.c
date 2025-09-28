// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H
#include "keymap_custom.h"
#include "keymap_uk.h"
#include "keys.h"
#include <stdio.h>


enum tap_dance_codes {
    DANCE_4,
    DANCE_6,
    DANCE_7,
    DANCE_8,
    DANCE_9,
    DANCE_10,
    DANCE_11,
    DANCE_12,
};

#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define KC_NA KC_TRANSPARENT

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

#include "g/keymap_combo.h"
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=false;
  //debug_keyboard=true;
  //debug_mouse=true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_ben_split_3x5_3(
/*left side*/
KC_Q               , KC_W                  , LT_F       , LT_P       , KC_B             ,
 HRM_A,HRM_R     ,HRM_S,HRM_T,KC_G              ,
LT_Z         , LT_X            , LT_C       , LT_D       , KC_V             ,
MT(MOD_LCTL, KC_DELETE), KC_SPACE         , AL_THMB3,

/*right side*/
 KC_J              , LT_L            , LT_U       , KC_Y             , TD(DANCE_4)      ,
 KC_M              , HRM_N    ,HRM_E,HRM_I,HRM_O,
 KC_K              , LT_H            , LT_COMMA   , KC_DOT           , UK_DQUO          ,
QK_LEAD,               KC_BSPC, QK_REPEAT_KEY
  ),

  [1] = LAYOUT_ben_split_3x5_3(
  /*left side*/
 KC_NA      , UK_BSLS              , UK_LABK   , UK_RABK     , UK_PERC              ,
 TD(DANCE_6), MT(MOD_LALT, UK_SCLN),TD(DANCE_7), TD(DANCE_8) , UK_PLUS              ,
 UK_LPRN    , UK_RPRN              , UK_LBRC   , UK_RBRC     , UK_MINS              ,
 LLOCK      , UK_SCLN              , KC_NA     ,
 /*right side*/
 UK_AT      , UK_QUES              , UK_PIPE   , UK_ASTR     , UK_GRV               ,
 UK_CIRC    , MT(MOD_RCTL, UK_EQL) ,TD(DANCE_9), TD(DANCE_10), MT(MOD_RGUI, UK_MINS),
 UK_TILD    , UK_EXLM              , UK_UNDS   , UK_SLSH     , UK_HASH              ,
 KC_NA      , KC_LPRN              , KC_ENTER
  ),
  [2] = LAYOUT_ben_split_3x5_3(
  /*left side*/
MS_WHLD, MS_LEFT         , MS_DOWN    , MS_RGHT   , MS_ACL0,
KC_NA        , KC_NA              , KC_NA         , KC_NA         , MS_ACL1,
KC_PC_UNDO   , KC_PC_CUT          , KC_PC_COPY    , KC_PC_PASTE   , MS_ACL2,
LLOCK        , MS_WHLD      , KC_NA         ,
/*right side*/
LCTL(KC_Z)   , LSFT(KC_INSERT)    ,LCTL(KC_INSERT),LSFT(KC_DELETE),LCTL(KC_Y)   ,
KC_LEFT      , KC_DOWN            , KC_UP         , KC_RIGHT      , KC_PAUSE    ,
KC_HOME      , KC_PGDN            , KC_PGUP       , KC_END        , KC_INSERT   ,
KC_NA        , LCTL(MS_WHLD),LCTL(MS_WHLU)
  ),
  [3] = LAYOUT_ben_split_3x5_3(
  /*left side*/
 LSFT(KC_TAB)  , KC_F1, KC_F2, KC_F3, KC_F10,
 KC_TAB        , KC_F4, KC_F5, KC_F6, KC_F11,
 KC_APPLICATION, KC_F7, KC_F8, KC_F9, KC_F12,
 KC_NA         , KC_NA, KC_NA,
 /*right side*/
 KC_NA         , KC_NA, KC_NA, KC_NA, KC_NA ,
 KC_NA         , KC_NA, KC_NA, KC_NA, KC_NA ,
 KC_NA         , KC_NA, KC_NA, KC_NA, KC_NA ,
 KC_NA         , KC_NA, KC_NA
  ),
  [4] = LAYOUT_ben_split_3x5_3(
  /*left side*/
 KC_NA      , KC_NA, KC_NA, KC_NA, KC_NA       ,
 KC_NA      , KC_NA, KC_NA, KC_NA, KC_NA       ,
 KC_NA      , KC_NA, KC_NA, KC_NA, KC_NA       ,
 KC_NA      , KC_NA, KC_NA,
 /*right side*/
 UK_0       , UK_1 , UK_2 , UK_3 , TD(DANCE_11),
 KC_KP_MINUS, UK_4 , UK_5 , UK_6 , KC_KP_DOT   ,
 KC_KP_PLUS , UK_7 , UK_8 , UK_9 , KC_KP_COMMA ,
 KC_NA      , KC_NA, KC_NA
  ),
  [5] = LAYOUT_ben_split_3x5_3(
  /*left side*/
 LSFT(KC_TAB)  , KC_F1, KC_F2, KC_F3, KC_F10      ,
 KC_TAB        , KC_F4, KC_F5, KC_F6, KC_F11      ,
 KC_APPLICATION, KC_F7, KC_F8, KC_F9, KC_F12      ,
 KC_NA         , KC_NA, KC_NA,
 /*right side*/
 UK_0          , UK_1 , UK_2 , UK_3 , TD(DANCE_12),
 KC_KP_MINUS   , UK_4 , UK_5 , UK_6 , KC_KP_DOT   ,
 KC_KP_PLUS    , UK_7 , UK_8 , UK_9 , KC_KP_COMMA ,
 KC_NA         , KC_NA, KC_NA
  ),
};

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
        tap_code16(KC_KP_ASTERISK);
        tap_code16(KC_KP_ASTERISK);
        tap_code16(KC_KP_ASTERISK);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_ASTERISK);
    }
}

void dance_12_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(KC_KP_ASTERISK); break;
        case SINGLE_HOLD: register_code16(KC_KP_SLASH); break;
        case DOUBLE_TAP: register_code16(KC_KP_ASTERISK); register_code16(KC_KP_ASTERISK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_ASTERISK); register_code16(KC_KP_ASTERISK);
    }
}

void dance_12_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_ASTERISK); break;
        case SINGLE_HOLD: unregister_code16(KC_KP_SLASH); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_ASTERISK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_ASTERISK); break;
    }
    dance_state[12].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
        [DANCE_10] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
        [DANCE_11] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_11, dance_11_finished, dance_11_reset),
        [DANCE_12] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset),
};

// custom
const key_override_t apo_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_QUOTE);
const key_override_t dash_key_override = ko_make_basic(MOD_MASK_SHIFT, LT_COMMA, UK_MINS);
const key_override_t dquote_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_DQUO, UK_UNDS);
const key_override_t coln_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_COLN, UK_SCLN);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&apo_key_override,
	&dash_key_override,
    &dquote_key_override,
    &coln_key_override
};

bool is_flow_tap_key(uint16_t keycode) {
    // uprintf("is_flow_tab_key: %u\n", keycode);
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        case KC_SPC:
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record,
                           uint16_t prev_keycode) {
    dprintf("get_flow_tab_term: %u, %u\n", keycode, prev_keycode);
    // get_keycode_string reuses buffer, cannot be in same format string
    uprintf("get_flow_tab_term translate: %s", get_keycode_string(keycode));
    uprintf(", %s\n", get_keycode_string(prev_keycode));
    if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
        switch (keycode) {
            case LT_C:
            case LT_COMMA:
            case HRM_S:
            case HRM_E:
            case LT_F:
              dprintf("disabling flow tap\n");
              return 0;  // Short timeout on these keys.

            default:
              return FLOW_TAP_TERM;  // Longer timeout otherwise.
        }
    }
    return 0;  // Disable Flow Tap.
}
