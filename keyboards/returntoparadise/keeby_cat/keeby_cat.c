/* SPDX-License-Identifier: GPL-2.0-or-later */

#include "keeby_cat.h"
#include "oled.c"

// OLED images
// #include "keeby_cat_logo.c"

// bool oled_task_kb(void) {
//     if (!oled_task_user()) return false;
//     render_logo();
//     return true;
// }

// LED mapping
led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {
   NO_LED,
   11,	4,	3,
   10,	5,	2,
   9,	6,	1,
   8,	7,	0
   }
}, {
  // LED Index to Physical Position
  //   x = 224 / (NUMBER_OF_COLS - 1) * COL_POSITION
  // y =  64 / (NUMBER_OF_ROWS - 1) * ROW_POSITION
  //1           2            3            4             5
  { 224, 64 }, { 224, 43 }, { 224, 21 }, { 224, 0 }, { 112, 0 }, { 112, 21 }, { 112, 43 }, { 112, 64 }, { 0, 64 }, { 0, 43 }, { 0, 21 }, { 0, 0 },
}, {
  // LED Index to Flag
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
} };
