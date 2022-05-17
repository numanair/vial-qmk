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

//Sets up what the OLED screens display.

bool key_status_kb(void);

// #ifdef OLED_DRIVER_ENABLE

//     oled_write_P(qmk_logo, false);
// }

// static void print_status_narrow(void) {
//     // Print current mode
//     oled_write_P(PSTR("\n\n"), false);

//     switch (get_highest_layer(layer_state)) {
//         case 0:
//             oled_write_ln_P(PSTR("Qwrt"), false);
//             break;
//         case 1:
//             oled_write_ln_P(PSTR("Clmk"), false);
//             break;
//         default:
//             oled_write_P(PSTR("Mod\n"), false);
//             break;
//     }
//     oled_write_P(PSTR("\n\n"), false);
//     // Print current layer
//     oled_write_ln_P(PSTR("LAYER"), false);
//     switch (get_highest_layer(layer_state)) {
//         case 0:
//         case 1:
//             oled_write_P(PSTR("Base\n"), false);
//             break;
//         case 2:
//             oled_write_P(PSTR("Raise"), false);
//             break;
//         case 3:
//             oled_write_P(PSTR("Lower"), false);
//             break;
//         default:
//             oled_write_ln_P(PSTR("Undef"), false);
//     }
//     oled_write_P(PSTR("\n\n"), false);
//     led_t led_usb_state = host_keyboard_led_state();
//     oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
// }

// void oled_task_user(void) {
//     if (is_keyboard_master()) {
//         print_status_narrow();
//     } else {
//         render_logo();
//     }
// }

// #endif

#ifdef OLED_ENABLE

// Set OLED rotation
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
    return rotation;
}

#include "oled_keeby_cat_logo.c"
// #include "oled_graphic_test.c"

#define _BASE       0
#define _BROWSER    1
#define _GAME       2
#define _MEDIA      3

bool oled_task_user(void) {

    // Layer Status
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            // Brightness
            // oled_write_P(PSTR("Base\n"), false);
            render_logo();
            if(!is_oled_scrolling()){
                oled_scroll_left();
            }
            break;
        case _BROWSER:
            // render_oled_test();
            // oled_write_P(PSTR("Layer: "), false);
            rgb_matrix_enable_noeeprom();
            // rgb_matrix_sethsv_noeeprom(HSV_ORANGE);
            for (uint8_t i = 0; i < 3; i++){
                const uint8_t led_index_L1[] = {3, 4, 11};
                rgb_matrix_set_color(led_index_L1[i],RGB_WHITE);
            }
            if(is_oled_scrolling()){
                oled_scroll_off();
            }
            oled_write_P(PSTR("BROWSER\n"), false);
            key_status_kb();
            break;
        case _GAME:
            if(is_oled_scrolling()){
                oled_scroll_off();
            }
            oled_write_P(PSTR("GAME\n"), false);
            key_status_kb();
            break;
        case _MEDIA:
            // oled_write_P(PSTR("Layer: "), false);
            oled_write_P(PSTR("MEDIA\n"), false);
            if(is_oled_scrolling()){
                oled_scroll_off();
            }
            key_status_kb();
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            // oled_write_ln_P(PSTR("Undefined"), false);
            if(is_oled_scrolling()){
                oled_scroll_off();
            }
            key_status_kb();
    }

    return false;
}

bool key_status_kb(void){
    // oled_write_P(PSTR("Layer: "), false);
    // Keyboard Status Indicators
    led_t led_state = host_keyboard_led_state();
    oled_write_P(!led_state.num_lock ? PSTR("NUM OFF") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    return false;
}

#endif
