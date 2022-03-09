/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xD1B1
#define DEVICE_VER      0x0001
#define MANUFACTURER    Return to Paradise
#define PRODUCT         keeby-cat

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 15

/* Keyboard Matrix Assignments */
#define DIRECT_PINS {{ B12, B7, B6, B13, B14, B15, A8, A9, A10, A15, B3, B4, A2, A1, A0 }}

// #define ENCODERS_PAD_A {  }
// #define ENCODERS_PAD_B {  }

#define MIDI_ADVANCED

#define RGB_DI_PIN B9
#ifdef RGB_DI_PIN
//   #define LED_MATRIX_CENTER { 112, 32 }
  #define DRIVER_LED_TOTAL 15
  #define RGBLED_NUM 15
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
  #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
  /*== all animations enable ==*/
  #define RGBLIGHT_ANIMATIONS
  #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
  #define RGB_MATRIX_KEYPRESSES
  #define WS2812_BYTE_ORDER 1 //WS2812_BYTE_ORDER_GRB
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Use 1000hz polling */
#define USB_POLLING_INTERVAL_MS 1
