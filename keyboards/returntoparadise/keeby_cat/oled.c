/* Copyright 2020 Josef Adamcik
 * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// Sets up what the OLED screens display.

bool key_status_kb(void);

#ifdef OLED_ENABLE

// Set OLED rotation
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
    return rotation;
}

// #    include "rgb_matrix_layers.c"
#    include "oled_graphic_layer_02_game.c"
#    include "oled_graphic_layer_01_media.c"
#    include "oled_graphic_layer_03_web.c"
#    include "oled_graphic_layer_04_numpad.c"

// #    include "oled_keeby_cat_logo.c"
// #include "oled_graphic_test.c"

#    define _BASE 0
#    define _BROWSER 1
#    define _GAME 2
#    define _MEDIA 3

bool oled_task_user(void) {
    // Layer Status
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            // Brightness
            // oled_write_P(PSTR("Base\n"), false);
            // render_logo();
            // if (!is_oled_scrolling()) {
            //     oled_scroll_left();
            // }
            render_oled_layer_04_numpad();
            break;
        case _BROWSER:
            // render_oled_test();
            // oled_write_P(PSTR("Layer: "), false);
            rgb_matrix_enable_noeeprom();
            // rgb_matrix_sethsv_noeeprom(HSV_ORANGE);
            for (uint8_t i = 0; i < 3; i++) {
                // refer to "Key Matrix to LED Index" numbers in keeby_cat.c
                const uint8_t led_index[] = {3, 4, 11};
                rgb_matrix_set_color(led_index[i], RGB_WHITE);
            }
            for (uint8_t i = 0; i < 1; i++) {
                const uint8_t led_index[] = {7};
                rgb_matrix_set_color(led_index[i], RGB_RED);
            }
            rgb_matrix_set_color(1, RGB_ORANGE);
            rgb_matrix_set_color(9, RGB_BLUE);

            render_oled_layer_03_web();

            // if (is_oled_scrolling()) {
            //     oled_scroll_off();
            // }
            // oled_write_P(PSTR("BROWSER\n"), false);
            // key_status_kb();
            break;
        case _GAME:
            // if (is_oled_scrolling()) {
            //     oled_scroll_off();
            // }

            // oled_write_P(PSTR("GAME\n"), false);
            // key_status_kb();
            render_oled_layer_02_game();

            rgb_matrix_set_color(0, RGB_ORANGE);

            break;
        case _MEDIA:
            render_oled_layer_01_media();

            // oled_write_P(PSTR("Layer: "), false);
            // oled_write_P(PSTR("MEDIA\n"), false);
            // if (is_oled_scrolling()) {
            //     oled_scroll_off();
            // }
            // key_status_kb();
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            // oled_write_ln_P(PSTR("Undefined"), false);
            if (is_oled_scrolling()) {
                oled_scroll_off();
            }
            key_status_kb();
    }

    return false;
}

bool key_status_kb(void) {
    // oled_write_P(PSTR("Layer: "), false);
    // Keyboard Status Indicators
    led_t led_state = host_keyboard_led_state();
    oled_write_P(!led_state.num_lock ? PSTR("NUM OFF") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    return false;
}

#endif
