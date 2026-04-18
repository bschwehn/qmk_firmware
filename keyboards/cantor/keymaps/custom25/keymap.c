// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H
#include "keymap_custom.h"
#include "keymap_uk.h"
#include "print.h"

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
  debug_matrix=false;
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

    MT(MOD_LCTL, KC_DELETE),  KC_SPACE, KC_ENT,
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
    KC_SYSTEM_SLEEP, MS_WHLD,  MS_LEFT,     MS_DOWN,     MS_UP, MS_RGHT,
        KC_DOWN, KC_RGHT,     LSFT(KC_INSERT), LCTL(KC_INSERT), LSFT(KC_DELETE), KC_VOLU,

    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MS_ACL1,
    KC_HOME,        KC_PGDN,        KC_PGUP,          KC_END,       KC_PAUSE,       KC_MUTE,

    QK_BOOT, KC_PC_UNDO,     KC_PC_CUT,      KC_PC_COPY,     KC_PC_PASTE,    MS_ACL2,
    KC_UP, KC_LEFT,  KC_APP,    KC_SCRL,        KC_INSERT,         KC_VOLD,

    MS_WHLU,    MS_WHLD,  KC_TRANSPARENT,
    KC_TRANSPARENT, LCTL(MS_WHLD),LCTL(MS_WHLU)
  ),
  [LR_FUN] = LAYOUT_split_3x6_3(
    QK_DYNAMIC_TAPPING_TERM_PRINT, LSFT(KC_TAB),   KC_F1,          KC_F2,          KC_F3,          KC_F10,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    QK_DYNAMIC_TAPPING_TERM_DOWN, KC_TAB,         KC_F4,          KC_F5,          KC_F6,          KC_F11,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    QK_DYNAMIC_TAPPING_TERM_UP, KC_APPLICATION, KC_F7,          KC_F8,          KC_F9,          KC_F12,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [LR_NUM] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    UK_0,           UK_1,           UK_2,           UK_3,          KC_KP_ASTERISK ,   KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_KP_MINUS,    UK_4,           UK_5,           UK_6,           KC_KP_DOT,      KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_KP_PLUS, UK_7,        UK_8,           UK_9,           KC_KP_COMMA,    KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  /* note: accell has no effect in kinetic or accellerated mode */
  [LR_POINTER] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, CUSTOM_JIGGLE, MS_BTN3, MS_BTN1, MS_BTN2,  MS_ACL0,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, MS_ACL1,
    KC_TRANSPARENT, MS_BTN1, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, MS_ACL2,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MS_ACL0, KC_TRANSPARENT, KC_TRANSPARENT,

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
 // uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count); uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
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

// custom
#ifdef LEADER_ENABLE
void leader_end_user(void) {
    print("in leader_end_user\n");
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

const key_override_t *key_overrides[] = {
    &apo_key_override,
    &dash_key_override,
    &dquote_key_override,
    &coln_key_override
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
            case LT_D:
            case LT_F:
            case LT_P:
            case LT_U:
            case LT_X:
            case LT_Z:
            case LT_COMMA:
            case HRM_S:
            case HRM_E:
              dprintf("disabling flow tap\n");
              return 0;  // Short timeout on these keys.

            default:
              dprintf("flowing\n");
              return FLOW_TAP_TERM;  // Longer timeout otherwise.
        }
    }
    dprintf("disabling flow tap end\n");
    return 0;  // Disable Flow Tap.
}
