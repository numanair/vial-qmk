// Copyright 2024 Cole Morris
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"
#include "print96.h"

#if defined(RGB_MATRIX_ENABLE)

#define CAPS_LOCK_LED_INDEX 1
#define NUM_LOCK_LED_INDEX 0
#define LAYER_LED_INDEX 2

#define CAPS_LOCK_MAX_BRIGHTNESS RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define NUM_LOCK_MAX_BRIGHTNESS RGB_MATRIX_MAXIMUM_BRIGHTNESS

bool rgb_matrix_indicators_kb(void) {
    if (host_keyboard_led_state().caps_lock) {
        HSV indicator_color = {106, 250, brightness_plus_step()};
        RGB rgb = hsv_to_rgb(indicator_color);
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, rgb.r, rgb.g, rgb.b);
    }
    if (!host_keyboard_led_state().num_lock) { // inverted numlock light
        HSV indicator_color = {106, 250, brightness_plus_step()};
        RGB rgb = hsv_to_rgb(indicator_color);
        rgb_matrix_set_color(NUM_LOCK_LED_INDEX, rgb.r, rgb.g, rgb.b);
    }

    HSV layer_color = {HSV_RED}; // hsv_t upcoming change: https://github.com/qmk/qmk_firmware/pull/24471
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case 5:
            layer_color = (HSV){HSV_MAGENTA};
            break;
        case 4:
            layer_color = (HSV){HSV_ORANGE};
            break;
        case 3:
            layer_color = (HSV){HSV_GREEN};
            break;
        case 2:
            layer_color = (HSV){HSV_BLUE};
            break;
        case 1:
            layer_color = (HSV){HSV_YELLOW};
            break;
        default:
            break;
    }
    layer_color.v = brightness_plus_step();
    if(get_highest_layer(layer_state|default_layer_state) != 0){
        RGB rgb = hsv_to_rgb(layer_color); // rgb_t
        rgb_matrix_set_color(LAYER_LED_INDEX, rgb.r, rgb.b, rgb.g);
    }

    return true;
}

// one step more than current brightness
int brightness_plus_step(void) {
        uint8_t br = rgb_matrix_get_val();
        if (br < RGB_MATRIX_VAL_STEP) {
            br = RGB_MATRIX_VAL_STEP;
        } else if (br < (RGB_MATRIX_MAXIMUM_BRIGHTNESS - RGB_MATRIX_VAL_STEP)) {
            br += RGB_MATRIX_VAL_STEP;  // one step more than current brightness
        } else {
            br = RGB_MATRIX_MAXIMUM_BRIGHTNESS;
        }
        return br;
}

#endif
