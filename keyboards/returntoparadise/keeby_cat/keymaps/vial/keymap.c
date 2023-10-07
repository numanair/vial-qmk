/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H

#define ____ KC_TRNS

// Auto populate Tap Dance functions
void keyboard_post_init_user(void) {
    vial_tap_dance_entry_t td0 = { KC_KP_ENTER,
                                  KC_NUM_LOCK,
                                  KC_NO,
                                  KC_NO,
                                  TAPPING_TERM };
    vial_tap_dance_entry_t td1 = { KC_BTN1,
                                  KC_BTN3,
                                  KC_NO,
                                  KC_NO,
                                  TAPPING_TERM };
    vial_tap_dance_entry_t td2 = { KC_C,
                                  LSFT(KC_C),
                                  KC_NO,
                                  KC_NO,
                                  TAPPING_TERM };
    dynamic_keymap_set_tap_dance(0, &td0); // the first value corresponds to the TD(i) slot
    dynamic_keymap_set_tap_dance(1, &td1);
    dynamic_keymap_set_tap_dance(2, &td2);
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(TO(3), TO(1)) },
    [1] =   { ENCODER_CCW_CW(TO(0), TO(2)) },
    [2] =   { ENCODER_CCW_CW(TO(1), TO(3)) },
    [3] =   { ENCODER_CCW_CW(TO(2), TO(0)) }
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base (numpad)
    [0] = LAYOUT(
        KC_NUM_LOCK,
        KC_P0,   KC_PDOT, TD(0),
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,
        KC_P1,   KC_P2,   KC_P3
    ),
    // Browser / RES
    [1] = LAYOUT(
        KC_TRNS,
        KC_K,            KC_X,       KC_J,
        KC_LBRC,         TD(1),      KC_RBRC,
        KC_Z,            TD(2),      KC_A,
        LCTL(S(KC_TAB)), LCTL(KC_W), LCTL(KC_TAB)
    ),
    // Misc
    [2] = LAYOUT(
        KC_NO,
        KC_ESCAPE,   KC_NO,      KC_ENTER,
        KC_F10,      KC_F11,     KC_F12,
        KC_DELETE,   KC_DELETE,  KC_DELETE,
        KC_KP_MINUS, KC_KP_PLUS, RCTL(KC_F8)
    ),
    // Media
    [3] = LAYOUT(
        KC_TRNS,
        KC_MPRV, KC_MPLY, KC_MNXT,
        KC_F13, KC_F14, KC_F15,
        KC_F16, KC_F17, KC_F18,
        KC_F19, KC_F20, KC_TRNS
    )
};
