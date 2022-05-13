/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xD1B1
#define DEVICE_VER      0x0001
#define MANUFACTURER    Return to Paradise
#define PRODUCT         Keeby Cat

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 13

/* Keyboard Matrix Assignments */
// #define DIRECT_PINS {{ B12, B7, B6, B13, B14, B15, A8, A9, A10, A15, B3, B4, A2, A1, A0 }}
#define DIRECT_PINS {{ B12, B13, B14, B15, A8, A9, A10, A15, B3, B4, A2, A1, A0 }}

#define TAPPING_TOGGLE 2

#define ENCODERS_PAD_A { B11 }
#define ENCODERS_PAD_B { B10 }
// #define ENCODER_RESOLUTIONS { 2 }
// #define ENCODER_DIRECTION_FLIP

#define MIDI_ADVANCED

#define RGB_DI_PIN B9
#ifdef RGB_DI_PIN
//   #define LED_MATRIX_CENTER { 112, 32 }
  #define DRIVER_LED_TOTAL 12
  #define WS2812_BYTE_ORDER 1 //WS2812_BYTE_ORDER_GRB
  #define RGBLED_NUM 12
  #define RGBLIGHT_HUE_STEP 24
  #define RGBLIGHT_SAT_STEP 24
  #define RGBLIGHT_VAL_STEP 24
  #define RGB_MATRIX_MAXIMUM_BRIGHTNESS  255 /* The maximum brightness level */
  #define RGB_DISABLE_WHEN_USB_SUSPENDED   /* If defined, lighting will be switched off when the host goes to sleep */

//   #define ENABLE_RGB_MATRIX_ALPHAS_MODS
  #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
  #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
//   #define ENABLE_RGB_MATRIX_BREATHING
//   #define ENABLE_RGB_MATRIX_BAND_SAT
//   #define ENABLE_RGB_MATRIX_BAND_VAL
//   #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
//   #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
//   #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
//   #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
//   #define ENABLE_RGB_MATRIX_CYCLE_ALL
  #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
  #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN //good one
//   #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
//   #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
//   #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
  // #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
//   #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
//   #define ENABLE_RGB_MATRIX_DUAL_BEACON
//   #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
//   #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
//   #define ENABLE_RGB_MATRIX_RAINDROPS
//   #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
//   #define ENABLE_RGB_MATRIX_HUE_BREATHING
//   #define ENABLE_RGB_MATRIX_HUE_PENDULUM
//   #define ENABLE_RGB_MATRIX_HUE_WAVE
//   #define ENABLE_RGB_MATRIX_PIXEL_RAIN
//   #define ENABLE_RGB_MATRIX_PIXEL_FLOW
//   #define ENABLE_RGB_MATRIX_PIXEL_FRACTAL

  #define RGB_MATRIX_KEYPRESSES

#if defined(RGB_MATRIX_KEYPRESSES) || defined(RGB_MATRIX_KEYRELEASES)
  #define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50 // default 25ms

  #define RGB_MATRIX_FRAMEBUFFER_EFFECTS // Required for reactive defines

  #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
  #define ENABLE_RGB_MATRIX_DIGITAL_RAIN

  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
//   #define ENABLE_RGB_MATRIX_SOLID_SPLASH

#endif
#endif

/* Debounce - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Use 1000hz polling */
#define USB_POLLING_INTERVAL_MS 1
