// Copyright 2024 Cole Morris
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    if (host_keyboard_led_state().caps_lock)
    {
        rgb_matrix_set_color(0, 35, 35, 35);
    }
    if (!host_keyboard_led_state().num_lock)
    {
        rgb_matrix_set_color(1, 8, 78, 23);
    }
    return true;
}

#endif
