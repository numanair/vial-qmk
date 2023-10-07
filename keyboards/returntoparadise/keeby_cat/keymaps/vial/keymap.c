/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H

#define ____ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base (numpad)
    [0] = LAYOUT(
        TO(1),
        KC_P0,   KC_PDOT, KC_NUM_LOCK,
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,
        KC_P1,   KC_P2,   KC_P3
    ),
    // Browser / RES
    [1] = LAYOUT(
        TO(2),
        KC_J,        KC_X, KC_K,
        KC_LBRC, KC_X, KC_RBRC,
        KC_Z,        KC_C, KC_A,
        LCTL(S(KC_TAB)), LCTL(KC_W), LCTL(KC_TAB)
    ),
    // Misc
    [2] = LAYOUT(
        TO(3),
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
    // Media
    [3] = LAYOUT(
        TO(0),
        KC_MPRV, KC_MPLY, KC_MNXT,
        KC_F13, KC_F14, KC_F15,
        KC_F16, KC_F17, KC_F18,
        KC_F19, KC_F20, KC_F21
    )
};
