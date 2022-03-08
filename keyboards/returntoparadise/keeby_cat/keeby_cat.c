/* SPDX-License-Identifier: GPL-2.0-or-later */

#include "keeby_cat.h"
//NO_LED

led_config_t g_led_config = { {
  // Key Matrix to LED Index
  { 13, 14, 15,
   12,  5,  4,
   11,  6,  3,
   10,  7,  2,
    9,  8,  1 }
}, {
  // LED Index to Physical Position
  //   x = 224 / (NUMBER_OF_COLS - 1) * COL_POSITION
  // y =  64 / (NUMBER_OF_ROWS - 1) * ROW_POSITION
  //1           2            3            4             5
  { 224, 64 }, { 224, 48 }, { 224, 32 }, { 224, 16 }, { 112, 16 }, { 112, 32 }, { 112, 48 }, { 112, 64 }, { 0, 64 }, { 0, 48 }, { 0, 32 }, { 0, 16 }, { 0, 0 }, { 112, 0 }, { 224, 0 }
}, {
  // LED Index to Flag
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
} };
