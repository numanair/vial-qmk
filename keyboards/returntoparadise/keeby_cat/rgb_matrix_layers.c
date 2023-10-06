// Examples :id=indicator-examples
// This example sets the modifiers to be a specific color based on the layer state.
// You can use a switch case here, instead, if you would like.
// This uses HSV and then converts to RGB, because this allows the brightness to be limited.

/*/

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    HSV hsv = {0, 255, 255};

    if (layer_state_is(layer_state, 2)) {
        hsv = {130, 255, 255};
    } else {
        hsv = {30, 255, 255};
    }

    if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }
    RGB rgb = hsv_to_rgb(hsv);

    for (uint8_t i = led_min; i <= led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], 0x01)) { // 0x01 == LED_FLAG_MODIFIER
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
}

/*/

#define _BASE 0
#define _BROWSER 1
#define _GAME 2
#define _MEDIA 3

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            render_oled_layer_04_numpad();
            break;
        case _BROWSER:
            render_oled_layer_03_web();
            break;
        case _GAME:
            render_oled_layer_02_game();
            break;
        case _MEDIA:
            render_oled_layer_01_media();
            break;
    }
}
