#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif
#include "config.h"
#include "keymap_custom.h"
#include "keymap_uk.h"

#define KC_NA KC_TRANSPARENT

#define AL_BSPC LT(LR_EXTRAS, KC_BSPC)
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LR_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5,                 KC_6, KC_7, KC_8, KC_9, KC_0, MS_BTN1,
        KC_TAB, KC_Q, KC_W, LT_F, LT_P, KC_B, KC_J,              LT_L, LT_U, KC_Y, UK_COLN, KC_APPLICATION,
       KC_ESC,    HRM_A,   HRM_R,   HRM_S,   HRM_T,   KC_G,      KC_M,    HRM_N,   HRM_E,   HRM_I,   HRM_O,  QK_ALT_REPEAT_KEY,
        KC_LCTL,    LT_Z,    LT_X,    LT_C,    LT_D,    KC_V,    KC_K,    LT_H,  LT_COMMA, KC_DOT,  UK_DQUO, TT(LR_POINTER), //TT not working for some reason
        MT(MOD_LCTL, KC_DELETE),  KC_SPACE, KC_ENT,              QK_LEAD,  AL_BSPC,
        MT(MOD_LCTL, KC_DEL), QK_LLCK,                           QK_REPEAT_KEY
    ),

  [LR_BRACES] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RM_NEXT,/*TURBO*/KC_NA,UK_BSLS,UK_LABK,UK_RABK,UK_PERC,  UK_AT, UK_QUES, UK_PIPE, UK_ASTR, UK_GRV, KC_NA,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RM_TOGG,UK_COLN,    UK_SCLN, UK_LCBR,    UK_RCBR,    UK_PLUS,     UK_CIRC,        UK_EQL,     UK_AMPR,    UK_DLR,   UK_MINS, KC_PEQL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RM_PREV, UK_LPRN, UK_RPRN, UK_LBRC, UK_RBRC, UK_MINS,   UK_TILD, UK_EXLM, UK_UNDS, UK_SLSH, UK_HASH, KC_PDOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
       /*LLOCK*/
       KC_NA, KC_NA, KC_NA,    KC_NA, KC_NA,
       KC_NA, KC_NA, KC_NA
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LR_NAV] = LAYOUT(
                                  // LCTL(KC_Z), KC_HOME, LSFT(KC_INSERT), KC_PGDN,
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_MNXT, MS_WHLD, MS_LEFT, MS_DOWN, MS_UP, MS_RGHT,        KC_DOWN, KC_RIGHT, LSFT(KC_INSERT), LCTL(KC_INSERT), LSFT(KC_DELETE), KC_VOLU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_MPLY, KC_NA, KC_NA, KC_NA, KC_NA, KC_NA,               KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_PAUSE, KC_MUTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_MPRV, KC_NA, KC_NA, KC_NA, KC_NA, KC_NA,               KC_UP, KC_LEFT, KC_APP, KC_SCRL, KC_INSERT, KC_VOLD,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_NA, KC_NA, KC_NA,            KC_NA, KC_NA,
                                           KC_NA, KC_NA,          KC_NA
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LR_FUN] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_MNXT, LSFT(KC_TAB)  , KC_F1, KC_F2, KC_F3, KC_F10,    KC_NA, KC_NA, KC_NA, KC_NA, KC_NA, KC_VOLU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_MPLY, KC_TAB        , KC_F4, KC_F5, KC_F6, KC_F11,    KC_NA, KC_NA, KC_NA, KC_NA, KC_NA, KC_MUTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_MPRV, KC_APPLICATION, KC_F7, KC_F8, KC_F9, KC_F12,    KC_NA, KC_NA, KC_NA, KC_NA, KC_NA, KC_VOLD,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
        KC_NA, KC_NA, KC_NA,    KC_NA, KC_NA,
        KC_NA, KC_NA,    KC_NA
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LR_NUM] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_MNXT,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,      UK_0,    UK_1,    UK_2,    UK_3,   KC_KP_ASTERISK, KC_NA,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_MPLY,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,    KC_KP_MINUS, UK_4,  UK_5,    UK_6,   KC_KP_DOT, KC_MUTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_MPRV,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,    KC_KP_PLUS , UK_7,  UK_8,    UK_9,   KC_COMMA, KC_VOLD,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
        KC_NA, KC_NA, KC_NA,    KC_NA, KC_NA,
        KC_NA, KC_NA,    KC_NA
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LR_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
                KC_NA, KC_NA, KC_NA, KC_NA, KC_NA, KC_NA,    QK_BOOT, QK_REBOOT, KC_NA, KC_NA, KC_NA, KC_NA,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
            KC_NA, CUSTOM_JIGGLE, MS_BTN3, MS_BTN1, MS_BTN2,  MS_ACL0,    S_D_MOD, S_D_RMOD, DPI_MOD, DPI_RMOD, KC_NA, KC_NA,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NA, MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, MS_ACL1,    KC_NA, MS_BTN1, MS_BTN2, MS_BTN3, KC_NA, KC_NA,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NA, MS_WHLL,   MS_WHLD,   MS_WHLU,   MS_WHLR, MS_ACL2,    KC_NA, KC_NA, SNIPING, DRGSCRL, KC_NA, KC_NA,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  MS_BTN2, MS_BTN1, MS_BTN3,    MS_BTN3, MS_BTN1,
                                           KC_NA, MS_BTN2,    MS_BTN2
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LR_EXTRAS] = LAYOUT(
    // note: MT from base works if pressed earlier, MT not working with custom keys
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
                KC_NA, KC_NA, KC_NA, KC_NA, KC_NA, KC_NA,    KC_NA, KC_NA, KC_NA, KC_NA, KC_NA, KC_NA,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
            KC_NA, KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,    KC_NA, KC_NA, CUSTOM_UUML, KC_NA, KC_NA, KC_NA,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
            KC_NA, CUSTOM_AUML, KC_LALT, KC_LSFT, KC_LCTL, KC_NA,    KC_NA, CUSTOM_DARROW, KC_LSFT, KC_LALT, CUSTOM_OUML, KC_NA,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
            KC_NA, KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,    KC_NA, CUSTOM_HTTPS, CUSTOM_ARROW, KC_NA, CUSTOM_EMPROP, KC_NA,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_NA, KC_NA, KC_NA,    KC_NA, KC_NA,
                                           KC_NA, KC_NA,    KC_NA
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
 // uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count); uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
 if (!custom_record_user(keycode, record)) { return false; }
 return true;
}
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
