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

#include OLED_FONT_H
#include "oled_graphic_numbers.c"
// #include "quantum.h"
// #include <stdbool.h>
// #include "matrix.h"

// #    include "rgb_matrix_layers.c"
// #    include "oled_graphic_layer_02_game.c"
// #    include "oled_graphic_layer_01_media.c"
// #    include "oled_graphic_layer_03_web.c"
// #    include "oled_graphic_layer_04_numpad.c"

#    include "oled_keeby_cat_logo.c"
// #include "oled_graphic_test.c"

uint16_t startup_timer;
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    startup_timer = timer_read();
    // Set OLED rotation
    return OLED_ROTATION_180;
    return rotation;
}

bool oled_task_kb(void) {
    static bool finished_logo = false;
    if ((timer_elapsed(startup_timer) < 3200) && !finished_logo) {
        render_logo();
    } else {
        finished_logo = true;
        if (!oled_task_user()) {
            return false;
        }
    }
    return true;
}

// From evo70
void oled_write_char_at_pixel_xy(uint8_t x, uint8_t y, const char data, const unsigned char *fontselect, bool invert) {
    uint8_t i, j, temp;
    uint8_t cast_data = (uint8_t)data;

    const uint8_t *glyph = &fontselect[((uint8_t)cast_data - OLED_FONT_START) * OLED_FONT_WIDTH];
    temp = pgm_read_byte(glyph);
    for (i = 0; i < OLED_FONT_WIDTH ; i++) {
        for (j = 0; j < OLED_FONT_HEIGHT; j++) {
            if (temp & 0x01) {
                oled_write_pixel(x + i, y + j, !invert);
            } else {
                oled_write_pixel(x + i, y + j, invert);
            }
            temp >>= 1;
        }
        temp = pgm_read_byte(++glyph);
    }
}

void oled_write_chars_at_pixel_xy(uint8_t x, uint8_t y, const char *data, uint8_t length, const unsigned char *fontselect, bool invert) {
    uint8_t offset = 0;
    for (uint8_t i = 0; i < length; i++) {
        oled_write_char_at_pixel_xy(x + offset, y, data[i], fontselect, invert);
        offset += OLED_FONT_WIDTH;
    }
}

#    define _BASE 0
#    define _BROWSER 1
#    define _GAME 2
#    define _MEDIA 3

bool oled_task_user(void) {
    // Layer Status
    // https://joric.github.io/qle/
    static const uint8_t spritemap_x_max = 48;
    static const uint8_t fontmap_x_max = 42;
    char string_print_layer[3][3] = {
        {0,   1,  0},
        {48, 49, 50},
        {96, 97, 98}
    };
    char big_A[4][2] = {
        {0, 1},
        {0, 1},
        {0, 1},
        {0, 1},
    };
    for (uint8_t i = 0; i < 4; i++) {
        for (uint8_t j = 0; j < 2; j++) {
            big_A[i][j] += fontmap_x_max * i;
        }
    }

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            // Draw large 'A'
            const uint8_t yrepeats = 4;
            const uint8_t xrepeats = 2;
            for (uint8_t i = 0; i < yrepeats; i++) {
                oled_write_chars_at_pixel_xy(33, i*8, big_A[i], xrepeats, keeby_cat_font, 0);
            }

            string_print_layer[1][1] = 56; // 0
            string_print_layer[2][1] = string_print_layer[1][1] + spritemap_x_max; // 0
            for (uint8_t i = 0; i < 3; i++) {
                oled_write_chars_at_pixel_xy(103, i*8, string_print_layer[i], 3, keeby_cat_glyphs, 0);
            }

            oled_write_chars_at_pixel_xy(0, 0, " ", 1, font, 1);
            oled_write_chars_at_pixel_xy(1, 8, " ", 1, font, 1);

            // render_oled_layer_04_numpad();
            break;
        case _BROWSER:
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

            string_print_layer[1][1] = 49; // 1
            string_print_layer[2][1] = string_print_layer[1][1] + spritemap_x_max; // 1
            for (uint8_t i = 0; i < 3; i++) {
                oled_write_chars_at_pixel_xy(103, i*8, string_print_layer[i], 3, keeby_cat_glyphs, 0);
            }

            // render_oled_layer_03_web();

            // key_status_kb();
            break;
        case _GAME:
            // key_status_kb();
            // render_oled_layer_02_game();

            rgb_matrix_set_color(0, RGB_ORANGE);

            string_print_layer[1][1] = 51; // 2
            string_print_layer[2][1] = string_print_layer[1][1] + spritemap_x_max; // 2
            for (uint8_t i = 0; i < 3; i++) {
                // oled_set_cursor(17, i);
                oled_write_chars_at_pixel_xy(103, i*8, string_print_layer[i], 3, keeby_cat_glyphs, 0);
            }
            break;
        case _MEDIA:
            string_print_layer[1][1] = 52; // 3
            string_print_layer[2][1] = string_print_layer[1][1] + spritemap_x_max; // 3
            for (uint8_t i = 0; i < 3; i++) {
                // oled_set_cursor(17, i);
                oled_write_chars_at_pixel_xy(103, i*8, string_print_layer[i], 3, keeby_cat_glyphs, 0);
            }

            // key_status_kb();
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            // oled_write_ln_P(PSTR("Undefined"), false);
            if (is_oled_scrolling()) {
                oled_scroll_off();
            }
            key_status_kb();
            // render_oled_layer_01_media();
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

void suspend_power_down_user(void) {
    oled_off();
}

#endif
