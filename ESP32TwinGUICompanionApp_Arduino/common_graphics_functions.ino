void init_tfts() {
  tft_1.begin();
  tft_2.begin();
  tft_1.fillScreen(GC9A01A_BLACK);
  tft_2.fillScreen(GC9A01A_BLACK);
  testFilledRoundRects();
  tft_1.drawBitmap(38, 54, dqd, 150, 150, 0xFFFF);
  tft_2.drawBitmap(38, 54, dqd, 150, 150, 0xFFFF);
  yield();
}

void testFilledRoundRects() {

  int i, i2, cx = tft_1.width()  / 2 - 1, cy = tft_1.height() / 2 - 1;

  tft_1.fillScreen(GC9A01A_BLACK);
  tft_2.fillScreen(GC9A01A_BLACK);

  for (i = min(tft_1.width(), tft_1.height()); i > 20; i -= 6) {
    i2 = i / 2;
    tft_1.fillRoundRect(cx - i2, cy - i2, i, i, i / 8, tft_1.color565(i / 4, i, i / 2));
    tft_2.fillRoundRect(cx - i2, cy - i2, i, i, i / 8, tft_2.color565(i / 4, i, i / 2));
    yield();
  }
}
