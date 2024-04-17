void show_cpu_temp_val_tft_1(String temp_val, int text_colour) {
  tft_1.setCursor(59, 36); tft_1.setTextColor(GC9A01A_WHITE);  tft_1.setTextSize(4);  tft_1.println("CPU-T");
  tft_1.setCursor(96, 184); tft_1.setTextColor(GC9A01A_WHITE);  tft_1.setTextSize(4);  tft_1.println("^C");
  tft_1.setCursor(40, 98); tft_1.setTextColor(GC9A01A_BLACK);  tft_1.setTextSize(7);  tft_1.println(prev_cpu_temp_val);
  delay(10);
  tft_1.setCursor(40, 98); tft_1.setTextSize(7);
  switch (text_colour) {
    case 1:
      tft_1.setTextColor(GC9A01A_GREEN);
      tft_1.drawCircle(120, 120, 119, GC9A01A_GREEN);
      tft_1.drawCircle(120, 120, 118, GC9A01A_GREEN);
      tft_1.drawCircle(120, 120, 117, GC9A01A_GREEN);
      break;
    case 2:
      tft_1.setTextColor(GC9A01A_YELLOW);
      tft_1.drawCircle(120, 120, 119, GC9A01A_YELLOW);
      tft_1.drawCircle(120, 120, 118, GC9A01A_YELLOW);
      tft_1.drawCircle(120, 120, 117, GC9A01A_YELLOW);
      break;
    case 3:
      tft_1.setTextColor(GC9A01A_ORANGE);
      tft_1.drawCircle(120, 120, 119, GC9A01A_ORANGE);
      tft_1.drawCircle(120, 120, 118, GC9A01A_ORANGE);
      tft_1.drawCircle(120, 120, 117, GC9A01A_ORANGE);
      break;
    case 4:
      tft_1.setTextColor(GC9A01A_RED);
      tft_1.drawCircle(120, 120, 119, GC9A01A_RED);
      tft_1.drawCircle(120, 120, 118, GC9A01A_RED);
      tft_1.drawCircle(120, 120, 117, GC9A01A_RED);
      break;
    default:
      tft_1.setTextColor(GC9A01A_BLUE);
      tft_1.drawCircle(120, 120, 119, GC9A01A_BLUE);
      tft_1.drawCircle(120, 120, 118, GC9A01A_BLUE);
      tft_1.drawCircle(120, 120, 117, GC9A01A_BLUE);
      break;
  }

  tft_1.println(temp_val);
  prev_cpu_temp_val = temp_val;
}

void show_gpu_temp_val_tft_1(String temp_val, int text_colour) {
  tft_1.setCursor(59, 36); tft_1.setTextColor(GC9A01A_WHITE);  tft_1.setTextSize(4);  tft_1.println("GPU-T");
  tft_1.setCursor(96, 184); tft_1.setTextColor(GC9A01A_WHITE);  tft_1.setTextSize(4);  tft_1.println("^C");
  tft_1.setCursor(40, 98); tft_1.setTextColor(GC9A01A_BLACK);  tft_1.setTextSize(7);  tft_1.println(prev_gpu_temp_val);
  delay(10);
  tft_1.setCursor(40, 98); tft_1.setTextSize(7);
  switch (text_colour) {
    case 1:
      tft_1.setTextColor(GC9A01A_GREEN);
      tft_1.drawCircle(120, 120, 119, GC9A01A_GREEN);
      tft_1.drawCircle(120, 120, 118, GC9A01A_GREEN);
      tft_1.drawCircle(120, 120, 117, GC9A01A_GREEN);
      break;
    case 2:
      tft_1.setTextColor(GC9A01A_YELLOW);
      tft_1.drawCircle(120, 120, 119, GC9A01A_YELLOW);
      tft_1.drawCircle(120, 120, 118, GC9A01A_YELLOW);
      tft_1.drawCircle(120, 120, 117, GC9A01A_YELLOW);
      break;
    case 3:
      tft_1.setTextColor(GC9A01A_ORANGE);
      tft_1.drawCircle(120, 120, 119, GC9A01A_ORANGE);
      tft_1.drawCircle(120, 120, 118, GC9A01A_ORANGE);
      tft_1.drawCircle(120, 120, 117, GC9A01A_ORANGE);
      break;
    case 4:
      tft_1.setTextColor(GC9A01A_RED);
      tft_1.drawCircle(120, 120, 119, GC9A01A_RED);
      tft_1.drawCircle(120, 120, 118, GC9A01A_RED);
      tft_1.drawCircle(120, 120, 117, GC9A01A_RED);
      break;
    default:
      tft_1.setTextColor(GC9A01A_BLUE);
      tft_1.drawCircle(120, 120, 119, GC9A01A_BLUE);
      tft_1.drawCircle(120, 120, 118, GC9A01A_BLUE);
      tft_1.drawCircle(120, 120, 117, GC9A01A_BLUE);
      break;
  }

  tft_1.println(temp_val);
  prev_gpu_temp_val = temp_val;
}
