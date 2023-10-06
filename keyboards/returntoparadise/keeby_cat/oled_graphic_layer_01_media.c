static void render_oled_layer_01_media(void) {
  static const char PROGMEM oled_image[] = {

// 'media', 128x32px
0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0xf8, 0xf0, 0x00, 0x00, 0xf0, 0xf8, 0xf8, 0xf0, 0xe0,
0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xf0, 0xf8, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8,
0xf0, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0xf8, 0x38, 0x38, 0x38, 0x38, 0x38, 0x10, 0x00, 0x00, 0x00,
0xf0, 0xf8, 0xf8, 0x38, 0x38, 0x78, 0xf0, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x18, 0xf8, 0xf8, 0xf8,
0x18, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0x78, 0x38, 0x38, 0x78, 0xf0, 0xe0, 0x80, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xff, 0xff, 0xff, 0x0f, 0x3f, 0xfc, 0xf0, 0xc0, 0xf0, 0xfc, 0x3f, 0x0f, 0xff, 0xff,
0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff,
0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x30, 0x08, 0x04, 0x04, 0x02, 0x42,
0xe2, 0x02, 0x04, 0x04, 0x08, 0x30, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0xff, 0xff,
0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x07, 0x07, 0x07, 0x07, 0x07, 0x02, 0x00, 0x00, 0x00,
0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff,
0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x07, 0x07, 0x07, 0x07, 0xff, 0xff, 0xff, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0c, 0x10, 0x20, 0x20, 0x40, 0x40,
0x47, 0x40, 0x20, 0x20, 0x10, 0x0c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x1f, 0x1f, 0x0f, 0x00, 0x00, 0x0f, 0x1f, 0x1f, 0x0f, 0x07,
0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x0f, 0x1f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x1f,
0x0f, 0x00, 0x00, 0x00, 0x0f, 0x1f, 0x1f, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x08, 0x00, 0x00, 0x00,
0x0f, 0x1f, 0x1f, 0x1c, 0x1c, 0x1c, 0x0e, 0x0f, 0x07, 0x01, 0x00, 0x00, 0x18, 0x1f, 0x1f, 0x1f,
0x18, 0x00, 0x00, 0x00, 0x0f, 0x1f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x1f, 0x0f, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

  };

  oled_write_raw_P(oled_image, sizeof(oled_image));
};
