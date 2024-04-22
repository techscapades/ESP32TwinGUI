void init_tfts() {
  tft_1.begin();
  tft_2.begin();
  tft_1.setRotation(rotate_number);
  tft_2.setRotation(rotate_number);
  tft_1.fillScreen(GC9A01A_BLACK);
  tft_2.fillScreen(GC9A01A_BLACK);

  canvasL_1.setTextWrap(false);
  canvasR_1.setTextWrap(false);
  canvasL_2.setTextWrap(false);
  canvasR_2.setTextWrap(false);
  canvas_1.setTextWrap(false);
  canvas_2.setTextWrap(false);
  canvas_3.setTextWrap(false);


  canvasL_1.fillScreen(0);
  canvasR_1.fillScreen(0);
  canvasL_2.fillScreen(0);
  canvasR_2.fillScreen(0);
  canvas_1.fillScreen(0);
  canvas_2.fillScreen(0);
  canvas_3.fillScreen(0);

}

void refresh_all_screen_components() {
  tft_1.fillScreen(GC9A01A_BLACK);
  tft_2.fillScreen(GC9A01A_BLACK);
  canvasL_1.fillScreen(0);
  canvasR_1.fillScreen(0);
  canvasL_2.fillScreen(0);
  canvasR_2.fillScreen(0);
  canvas_1.fillScreen(0);
  canvas_2.fillScreen(0);
  canvas_3.fillScreen(0);
  tft_1_bg_drawn = false;
  tft_2_bg_drawn = false;
}

void refresh_screen_1_components() {
  tft_1.fillScreen(GC9A01A_BLACK);
  canvasL_1.fillScreen(0);
  canvasR_1.fillScreen(0);
  canvas_1.fillScreen(0);
  canvas_2.fillScreen(0);
  canvas_3.fillScreen(0);
  tft_1_bg_drawn = false;
}

void refresh_screen_2_components() {
  tft_2.fillScreen(GC9A01A_BLACK);
  canvasL_2.fillScreen(0);
  canvasR_2.fillScreen(0);
  canvas_1.fillScreen(0);
  canvas_2.fillScreen(0);
  canvas_3.fillScreen(0);
  tft_2_bg_drawn = false;
}

void display_homescreen_bmps() {
  if (millis() - previous_splash > interval_splash) {
    if (!serial_begun && !tft_1_bg_drawn && !tft_2_bg_drawn) {
      blackout_logo();
      uint16_t red_val, green_val, blue_val, tft_1_bmp_color, tft_2_bmp_color;
      red_val = 254 / brightness_divisor;
      green_val = 255 / brightness_divisor;
      blue_val = 254 / brightness_divisor;
      tft_1_bmp_color = tft_1.color565(red_val, green_val, blue_val); //dark grey
      tft_2_bmp_color = tft_1.color565(red_val, green_val, blue_val); //dark grey
      canvas_1.fillScreen(0);
      canvas_2.fillScreen(0);
      canvas_3.fillScreen(0);
      tft_1.fillScreen(GC9A01A_BLACK);
      tft_2.fillScreen(GC9A01A_BLACK);
      tft_1.drawBitmap(0, 0, clock_bg2 , 240, 240, tft_1_bmp_color, GC9A01A_BLACK);
      tft_2.drawBitmap(0, 0, clock_bg1 , 240, 240, tft_1_bmp_color, GC9A01A_BLACK);
      tft_1_bg_drawn = true;
      tft_2_bg_drawn = true;
    }
  }
}

void cycle_splash_screen() {
  if (!serial_begun) {
    if (millis() - previous_splash > interval_splash) {
      if (splash_number != 0 ) {
        blackout_logo();
      }
      splash_number += 1;
      if (splash_number > 8) {
        splash_number = 1;
      }
      draw_splash_screen(splash_number);
      previous_splash = millis();
    }
  }
}

void blackout_logo() {
  uint16_t red_val, green_val, blue_val;
  red_val = 252,
  green_val = 254;
  blue_val = 252;
  red_val = red_val / brightness_divisor;
  green_val = green_val / brightness_divisor;
  blue_val = blue_val / brightness_divisor;

  for (byte i = 1; i < 5; i++) {
    tft_1.drawBitmap(38, 54, dqd, 150, 150, GC9A01A_BLACK);
    tft_2.drawBitmap(38, 54, dqd, 150, 150, GC9A01A_BLACK);
    yield();
    tft_1.drawBitmap(38, 54, dqd, 150, 150, tft_1.color565(red_val, green_val, blue_val));
    tft_2.drawBitmap(38, 54, dqd, 150, 150, tft_2.color565(red_val, green_val, blue_val));
    yield();
  }
  tft_1.drawBitmap(38, 54, dqd, 150, 150, GC9A01A_BLACK);
  tft_2.drawBitmap(38, 54, dqd, 150, 150, GC9A01A_BLACK);
  yield();
}

void draw_splash_screen(byte color_scheme) {
  testFilledRoundRects(color_scheme);
  uint16_t red_val, green_val, blue_val;
  red_val = 254,
  green_val = 255;
  blue_val = 254;
  red_val = red_val / brightness_divisor;
  green_val = green_val / brightness_divisor;
  blue_val = blue_val / brightness_divisor;
  if (color_scheme == 8) {
    tft_1.drawBitmap(38, 54, dqd, 150, 150, GC9A01A_BLACK);
    tft_2.drawBitmap(38, 54, dqd, 150, 150, GC9A01A_BLACK);
  } else {
    tft_1.drawBitmap(38, 54, dqd, 150, 150, tft_1.color565(red_val, green_val, blue_val));
    tft_2.drawBitmap(38, 54, dqd, 150, 150, tft_2.color565(red_val, green_val, blue_val));
  }
  yield();
}

void testFilledRoundRects(byte color_scheme) {

  int i, i2, cx = tft_1.width()  / 2 - 1, cy = tft_1.height() / 2 - 1;
  uint16_t red_val, green_val, blue_val;

  switch (color_scheme) {
    case 1:
      red_val = 4,
      green_val = 1;
      blue_val = 2;
      break;
    case 2:
      red_val = 2,
      green_val = 4;
      blue_val = 1;
      break;
    case 3:
      red_val = 1,
      green_val = 2;
      blue_val = 4;
      break;
    case 4:
      red_val = 3,
      green_val = 2;
      blue_val = 3;
      break;
    case 5:
      red_val = 3,
      green_val = 3;
      blue_val = 2;
      break;
    case 6:
      red_val = 2,
      green_val = 3;
      blue_val = 3;
      break;
    case 7:
      red_val = 1,
      green_val = 1;
      blue_val = 1;
      break;
    case 8:
      red_val = 0,
      green_val = 0;
      blue_val = 0;
      break;
    default:
      red_val = 4,
      green_val = 1;
      blue_val = 2;
      break;
  }

  red_val = red_val * brightness_divisor;
  green_val = green_val * brightness_divisor;
  blue_val = blue_val * brightness_divisor;

  if (red_val == 0 && green_val == 0 && blue_val == 0) {
    for (i = min(tft_1.width(), tft_1.height()); i > 20; i -= 6) {
      i2 = i / 2;
      tft_1.fillRoundRect(cx - i2, cy - i2, i, i, i / 8, tft_1.color565(abs((254 - i) / brightness_divisor), abs((254 - i) / brightness_divisor), abs((254 - i) / brightness_divisor)));
      tft_2.fillRoundRect(cx - i2, cy - i2, i, i, i / 8, tft_2.color565(abs((254 - i) / brightness_divisor), abs((254 - i) / brightness_divisor), abs((254 - i) / brightness_divisor)));
      yield();
    }
  } else {
    for (i = min(tft_1.width(), tft_1.height()); i > 20; i -= 6) {
      i2 = i / 2;
      tft_1.fillRoundRect(cx - i2, cy - i2, i, i, i / 8, tft_1.color565(i / red_val, i / green_val, i / blue_val));
      tft_2.fillRoundRect(cx - i2, cy - i2, i, i, i / 8, tft_2.color565(i / red_val, i / green_val, i / blue_val));
      yield();
    }
  }
}
