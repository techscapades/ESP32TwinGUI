void show_cpu_temp_and_load_val_tft_1(String temp_val, String load_val, int temp_text_color, int load_text_color) {
  uint16_t red_val_L, green_val_L, blue_val_L, red_val_R, green_val_R, blue_val_R, canvasL_1_text_color, canvasR_1_text_color, canvasL_1_w_text_color, canvasR_1_w_text_color;

  canvasL_1.setCursor(16, 112);
  switch (temp_text_color) {
    case 1: //green
      red_val_L = 0;
      green_val_L = 255 / brightness_divisor;
      blue_val_L = 0;
      canvasL_1_text_color = tft_1.color565(red_val_L, green_val_L, blue_val_L);

      canvasL_1.setTextColor(canvasL_1_text_color, GC9A01A_BLACK);
      canvasL_1.drawCircle(120, 120, 119, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 118, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 117, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 116, canvasL_1_text_color);
      break;
    case 2: //yellow
      red_val_L = 255 / brightness_divisor;
      green_val_L = 255 / brightness_divisor;
      blue_val_L = 0;
      canvasL_1_text_color = tft_1.color565(red_val_L, green_val_L, blue_val_L);

      canvasL_1.setTextColor(canvasL_1_text_color, GC9A01A_BLACK);
      canvasL_1.drawCircle(120, 120, 119, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 118, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 117, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 116, canvasL_1_text_color);
      break;
    case 3: //orange
      red_val_L = 255 / brightness_divisor;
      green_val_L = 165 / brightness_divisor;
      blue_val_L = 0;
      canvasL_1_text_color = tft_1.color565(red_val_L, green_val_L, blue_val_L);

      canvasL_1.setTextColor(canvasL_1_text_color, GC9A01A_BLACK);
      canvasL_1.drawCircle(120, 120, 119, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 118, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 117, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 116, canvasL_1_text_color);
      break;
    case 4: //red
      red_val_L = 255 / brightness_divisor;
      green_val_L = 0;
      blue_val_L = 0;
      canvasL_1_text_color = tft_1.color565(red_val_L, green_val_L, blue_val_L);

      canvasL_1.setTextColor(canvasL_1_text_color, GC9A01A_BLACK);
      canvasL_1.drawCircle(120, 120, 119, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 118, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 117, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 116, canvasL_1_text_color);
      break;
    default://blue
      red_val_L = 0;
      green_val_L = 0;
      blue_val_L = 255 / brightness_divisor;
      canvasL_1_text_color = tft_1.color565(red_val_L, green_val_L, blue_val_L);

      canvasL_1.setTextColor(canvasL_1_text_color, GC9A01A_BLACK);
      canvasL_1.drawCircle(120, 120, 119, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 118, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 117, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 116, canvasL_1_text_color);
      break;
  }
  canvasL_1.setTextSize(4); canvasL_1.print(temp_val);
  yield();

  canvasR_1.setCursor(13, 112);
  switch (load_text_color) {
    case 1: //green
      red_val_R = 0;
      green_val_R = 255 / brightness_divisor;
      blue_val_R = 0;
      canvasR_1_text_color = tft_1.color565(red_val_R, green_val_R, blue_val_R);

      canvasR_1.setTextColor(canvasR_1_text_color, GC9A01A_BLACK);
      canvasR_1.drawCircle(0, 120, 119, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 118, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 117, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 116, canvasR_1_text_color);
      break;
    case 2: //yellow
      red_val_R = 255 / brightness_divisor;
      green_val_R = 255 / brightness_divisor;
      blue_val_R = 0;
      canvasR_1_text_color = tft_1.color565(red_val_R, green_val_R, blue_val_R);

      canvasR_1.setTextColor(canvasR_1_text_color, GC9A01A_BLACK);
      canvasR_1.drawCircle(0, 120, 119, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 118, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 117, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 116, canvasR_1_text_color);
      break;
    case 3: //orange
      red_val_R = 255 / brightness_divisor;
      green_val_R = 165 / brightness_divisor;
      blue_val_R = 0;
      canvasR_1_text_color = tft_1.color565(red_val_R, green_val_R, blue_val_R);

      canvasR_1.setTextColor(canvasR_1_text_color, GC9A01A_BLACK);
      canvasR_1.drawCircle(0, 120, 119, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 118, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 117, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 116, canvasR_1_text_color);
      break;
    case 4: //red
      red_val_R = 255 / brightness_divisor;
      green_val_R = 0;
      blue_val_R = 0;
      canvasR_1_text_color = tft_1.color565(red_val_R, green_val_R, blue_val_R);

      canvasR_1.setTextColor(canvasR_1_text_color, GC9A01A_BLACK);
      canvasR_1.drawCircle(0, 120, 119, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 118, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 117, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 116, canvasR_1_text_color);
      break;
    default://blue
      red_val_R = 0;
      green_val_R = 0;
      blue_val_R = 255 / brightness_divisor;
      canvasR_1_text_color = tft_1.color565(red_val_R, green_val_R, blue_val_R);

      canvasR_1.setTextColor(canvasR_1_text_color, GC9A01A_BLACK);
      canvasR_1.drawCircle(0, 120, 119, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 118, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 117, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 116, canvasR_1_text_color);
      break;
  }
  canvasR_1.setTextSize(4); canvasR_1.print(load_val);
  yield();

  //start of GUI layout
  red_val_L = 254 / brightness_divisor;
  green_val_L = 255 / brightness_divisor;
  blue_val_L = 254 / brightness_divisor;
  canvasL_1_w_text_color = tft_1.color565(red_val_L, green_val_L, blue_val_L);

  red_val_R = 254 / brightness_divisor;
  green_val_R = 255 / brightness_divisor;
  blue_val_R = 254 / brightness_divisor;
  canvasR_1_w_text_color = tft_1.color565(red_val_R, green_val_R, blue_val_R);

  //vertical white separator rectangles
  canvasL_1.fillRect(118, 50, 2, 240, canvasL_1_w_text_color);
  canvasR_1.fillRect(120, 50, 4, 240, canvasR_1_w_text_color);
  //horizontal black top and bottom bars
  canvasL_1.fillRect(0, 0, 240, 50, 0x0000); canvasR_1.fillRect(0, 0, 240, 50, 0x0000); //top
  canvasL_1.fillRect(0, 210, 240, 30, 0x0000); canvasR_1.fillRect(0, 210, 240, 30, 0x0000); //bottom
  //horizontal white separator rectangles
  canvasL_1.fillRect(27, 48, 120, 2, canvasL_1_w_text_color); canvasR_1.fillRect(0, 48, 94, 2, canvasR_1_w_text_color);

  canvasL_1.setCursor(83, 12); canvasL_1.setTextColor(canvasL_1_w_text_color, GC9A01A_BLACK); canvasL_1.setTextSize(4); canvasL_1.print("CPU");
  canvasR_1.setCursor(-34, 12); canvasR_1.setTextColor(canvasR_1_w_text_color, GC9A01A_BLACK); canvasR_1.setTextSize(4); canvasR_1.print("CPU");
  canvasL_1.setCursor(62, 60); canvasL_1.setTextColor(canvasL_1_w_text_color, GC9A01A_BLACK); canvasL_1.setTextSize(3); canvasL_1.print("T");
  canvasR_1.setCursor(43, 60); canvasR_1.setTextColor(canvasR_1_w_text_color, GC9A01A_BLACK); canvasR_1.setTextSize(3); canvasR_1.print("L");
  canvasL_1.setCursor(51, 175); canvasL_1.setTextColor(canvasL_1_w_text_color, GC9A01A_BLACK); canvasL_1.setTextSize(3); canvasL_1.print("^C");
  canvasR_1.setCursor(43, 175); canvasR_1.setTextColor(canvasR_1_w_text_color, GC9A01A_BLACK); canvasR_1.setTextSize(3); canvasR_1.print("%");
  //end of GUI layout
  yield();
  tft_1.drawRGBBitmap(0, 0, canvasL_1.getBuffer(), canvasL_1.width(), canvasL_1.height());
  tft_1.drawRGBBitmap(120, 0, canvasR_1.getBuffer(), canvasR_1.width(), canvasR_1.height());
  yield();
  prev_cpu_temp_val = temp_val;
  prev_cpu_load_val = load_val;
}

void show_gpu_temp_and_load_val_tft_1(String temp_val, String load_val, int temp_text_color, int load_text_color) {
  uint16_t red_val_L, green_val_L, blue_val_L, red_val_R, green_val_R, blue_val_R, canvasL_1_text_color, canvasR_1_text_color, canvasL_1_w_text_color, canvasR_1_w_text_color;

  canvasL_1.setCursor(16, 112);
  switch (temp_text_color) {
    case 1: //green
      red_val_L = 0;
      green_val_L = 255 / brightness_divisor;
      blue_val_L = 0;
      canvasL_1_text_color = tft_1.color565(red_val_L, green_val_L, blue_val_L);

      canvasL_1.setTextColor(canvasL_1_text_color, GC9A01A_BLACK);
      canvasL_1.drawCircle(120, 120, 119, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 118, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 117, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 116, canvasL_1_text_color);
      break;
    case 2: //yellow
      red_val_L = 255 / brightness_divisor;
      green_val_L = 255 / brightness_divisor;
      blue_val_L = 0;
      canvasL_1_text_color = tft_1.color565(red_val_L, green_val_L, blue_val_L);

      canvasL_1.setTextColor(canvasL_1_text_color, GC9A01A_BLACK);
      canvasL_1.drawCircle(120, 120, 119, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 118, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 117, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 116, canvasL_1_text_color);
      break;
    case 3: //orange
      red_val_L = 255 / brightness_divisor;
      green_val_L = 165 / brightness_divisor;
      blue_val_L = 0;
      canvasL_1_text_color = tft_1.color565(red_val_L, green_val_L, blue_val_L);

      canvasL_1.setTextColor(canvasL_1_text_color, GC9A01A_BLACK);
      canvasL_1.drawCircle(120, 120, 119, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 118, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 117, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 116, canvasL_1_text_color);
      break;
    case 4: //red
      red_val_L = 255 / brightness_divisor;
      green_val_L = 0;
      blue_val_L = 0;
      canvasL_1_text_color = tft_1.color565(red_val_L, green_val_L, blue_val_L);

      canvasL_1.setTextColor(canvasL_1_text_color, GC9A01A_BLACK);
      canvasL_1.drawCircle(120, 120, 119, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 118, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 117, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 116, canvasL_1_text_color);
      break;
    default://blue
      red_val_L = 0;
      green_val_L = 0;
      blue_val_L = 255 / brightness_divisor;
      canvasL_1_text_color = tft_1.color565(red_val_L, green_val_L, blue_val_L);

      canvasL_1.setTextColor(canvasL_1_text_color, GC9A01A_BLACK);
      canvasL_1.drawCircle(120, 120, 119, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 118, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 117, canvasL_1_text_color);
      canvasL_1.drawCircle(120, 120, 116, canvasL_1_text_color);
      break;
  }
  canvasL_1.setTextSize(4); canvasL_1.print(temp_val);
  yield();

  canvasR_1.setCursor(13, 112);
  switch (load_text_color) {
    case 1: //green
      red_val_R = 0;
      green_val_R = 255 / brightness_divisor;
      blue_val_R = 0;
      canvasR_1_text_color = tft_1.color565(red_val_R, green_val_R, blue_val_R);

      canvasR_1.setTextColor(canvasR_1_text_color, GC9A01A_BLACK);
      canvasR_1.drawCircle(0, 120, 119, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 118, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 117, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 116, canvasR_1_text_color);
      break;
    case 2: //yellow
      red_val_R = 255 / brightness_divisor;
      green_val_R = 255 / brightness_divisor;
      blue_val_R = 0;
      canvasR_1_text_color = tft_1.color565(red_val_R, green_val_R, blue_val_R);

      canvasR_1.setTextColor(canvasR_1_text_color, GC9A01A_BLACK);
      canvasR_1.drawCircle(0, 120, 119, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 118, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 117, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 116, canvasR_1_text_color);
      break;
    case 3: //orange
      red_val_R = 255 / brightness_divisor;
      green_val_R = 165 / brightness_divisor;
      blue_val_R = 0;
      canvasR_1_text_color = tft_1.color565(red_val_R, green_val_R, blue_val_R);

      canvasR_1.setTextColor(canvasR_1_text_color, GC9A01A_BLACK);
      canvasR_1.drawCircle(0, 120, 119, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 118, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 117, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 116, canvasR_1_text_color);
      break;
    case 4: //red
      red_val_R = 255 / brightness_divisor;
      green_val_R = 0;
      blue_val_R = 0;
      canvasR_1_text_color = tft_1.color565(red_val_R, green_val_R, blue_val_R);

      canvasR_1.setTextColor(canvasR_1_text_color, GC9A01A_BLACK);
      canvasR_1.drawCircle(0, 120, 119, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 118, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 117, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 116, canvasR_1_text_color);
      break;
    default://blue
      red_val_R = 0;
      green_val_R = 0;
      blue_val_R = 255 / brightness_divisor;
      canvasR_1_text_color = tft_1.color565(red_val_R, green_val_R, blue_val_R);

      canvasR_1.setTextColor(canvasR_1_text_color, GC9A01A_BLACK);
      canvasR_1.drawCircle(0, 120, 119, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 118, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 117, canvasR_1_text_color);
      canvasR_1.drawCircle(0, 120, 116, canvasR_1_text_color);
      break;
  }
  canvasR_1.setTextSize(4); canvasR_1.print(load_val);
  yield();

  //start of GUI layout
  red_val_L = 254 / brightness_divisor;
  green_val_L = 255 / brightness_divisor;
  blue_val_L = 254 / brightness_divisor;
  canvasL_1_w_text_color = tft_1.color565(red_val_L, green_val_L, blue_val_L);

  red_val_R = 254 / brightness_divisor;
  green_val_R = 255 / brightness_divisor;
  blue_val_R = 254 / brightness_divisor;
  canvasR_1_w_text_color = tft_1.color565(red_val_R, green_val_R, blue_val_R);

  //vertical white separator rectangles
  canvasL_1.fillRect(118, 50, 2, 240, canvasL_1_w_text_color);
  canvasR_1.fillRect(120, 50, 4, 240, canvasR_1_w_text_color);
  //horizontal black top and bottom bars
  canvasL_1.fillRect(0, 0, 240, 50, 0x0000); canvasR_1.fillRect(0, 0, 240, 50, 0x0000); //top
  canvasL_1.fillRect(0, 210, 240, 30, 0x0000); canvasR_1.fillRect(0, 210, 240, 30, 0x0000); //bottom
  //horizontal white separator rectangles
  canvasL_1.fillRect(27, 48, 120, 2, canvasL_1_w_text_color); canvasR_1.fillRect(0, 48, 94, 2, canvasR_1_w_text_color);

  canvasL_1.setCursor(83, 12); canvasL_1.setTextColor(canvasL_1_w_text_color, GC9A01A_BLACK); canvasL_1.setTextSize(4); canvasL_1.print("GPU");
  canvasR_1.setCursor(-34, 12); canvasR_1.setTextColor(canvasR_1_w_text_color, GC9A01A_BLACK); canvasR_1.setTextSize(4); canvasR_1.print("GPU");
  canvasL_1.setCursor(62, 60); canvasL_1.setTextColor(canvasL_1_w_text_color, GC9A01A_BLACK); canvasL_1.setTextSize(3); canvasL_1.print("T");
  canvasR_1.setCursor(43, 60); canvasR_1.setTextColor(canvasR_1_w_text_color, GC9A01A_BLACK); canvasR_1.setTextSize(3); canvasR_1.print("L");
  canvasL_1.setCursor(51, 175); canvasL_1.setTextColor(canvasL_1_w_text_color, GC9A01A_BLACK); canvasL_1.setTextSize(3); canvasL_1.print("^C");
  canvasR_1.setCursor(43, 175); canvasR_1.setTextColor(canvasR_1_w_text_color, GC9A01A_BLACK); canvasR_1.setTextSize(3); canvasR_1.print("%");
  //end of GUI layout
  yield();
  tft_1.drawRGBBitmap(0, 0, canvasL_1.getBuffer(), canvasL_1.width(), canvasL_1.height());
  tft_1.drawRGBBitmap(120, 0, canvasR_1.getBuffer(), canvasR_1.width(), canvasR_1.height());
  yield();
  prev_gpu_temp_val = temp_val;
  prev_gpu_load_val = load_val;
}

void show_cpu_temp_val_tft_1(String temp_val, int text_colour) {

  uint16_t red_val, green_val, blue_val, tft_1_text_color;
  red_val = 254 / brightness_divisor;
  green_val = 255 / brightness_divisor;
  blue_val = 254 / brightness_divisor;
  tft_1_text_color = tft_1.color565(red_val, green_val, blue_val);

  tft_1.setCursor(59, 36); tft_1.setTextColor(tft_1_text_color);  tft_1.setTextSize(4);  tft_1.println("CPU-T");
  tft_1.setCursor(96, 184); tft_1.setTextColor(tft_1_text_color);  tft_1.setTextSize(4);  tft_1.println("^C");
  tft_1.setCursor(40, 98); tft_1.setTextSize(7);

  switch (text_colour) {
    case 1: //green
      red_val = 0;
      green_val = 255 / brightness_divisor;
      blue_val = 0;
      tft_1_text_color = tft_1.color565(red_val, green_val, blue_val);

      tft_1.setTextColor(tft_1_text_color, GC9A01A_BLACK);
      tft_1.drawCircle(120, 120, 119, tft_1_text_color);
      tft_1.drawCircle(120, 120, 118, tft_1_text_color);
      tft_1.drawCircle(120, 120, 117, tft_1_text_color);
      break;
    case 2: //yellow
      red_val = 255 / brightness_divisor;
      green_val = 255 / brightness_divisor;
      blue_val = 0;
      tft_1_text_color = tft_1.color565(red_val, green_val, blue_val);

      tft_1.setTextColor(tft_1_text_color, GC9A01A_BLACK);
      tft_1.drawCircle(120, 120, 119, tft_1_text_color);
      tft_1.drawCircle(120, 120, 118, tft_1_text_color);
      tft_1.drawCircle(120, 120, 117, tft_1_text_color);
      break;
    case 3: //orange
      red_val = 255 / brightness_divisor;
      green_val = 165 / brightness_divisor;
      blue_val = 0;
      tft_1_text_color = tft_1.color565(red_val, green_val, blue_val);

      tft_1.setTextColor(tft_1_text_color, GC9A01A_BLACK);
      tft_1.drawCircle(120, 120, 119, tft_1_text_color);
      tft_1.drawCircle(120, 120, 118, tft_1_text_color);
      tft_1.drawCircle(120, 120, 117, tft_1_text_color);
      break;
    case 4: //red
      red_val = 255 / brightness_divisor;
      green_val = 0;
      blue_val = 0;
      tft_1_text_color = tft_1.color565(red_val, green_val, blue_val);

      tft_1.setTextColor(tft_1_text_color, GC9A01A_BLACK);
      tft_1.drawCircle(120, 120, 119, tft_1_text_color);
      tft_1.drawCircle(120, 120, 118, tft_1_text_color);
      tft_1.drawCircle(120, 120, 117, tft_1_text_color);
      break;
    default://blue
      red_val = 0;
      green_val = 0;
      blue_val = 255 / brightness_divisor;
      tft_1_text_color = tft_1.color565(red_val, green_val, blue_val);

      tft_1.setTextColor(tft_1_text_color, GC9A01A_BLACK);
      tft_1.drawCircle(120, 120, 119, tft_1_text_color);
      tft_1.drawCircle(120, 120, 118, tft_1_text_color);
      tft_1.drawCircle(120, 120, 117, tft_1_text_color);
      break;
  }

  tft_1.println(temp_val);
  prev_cpu_temp_val = temp_val;
  yield();
}

void show_gpu_temp_val_tft_1(String temp_val, int text_colour) {
  uint16_t red_val, green_val, blue_val, tft_1_text_color;
  red_val = 254 / brightness_divisor;
  green_val = 255 / brightness_divisor;
  blue_val = 254 / brightness_divisor;
  tft_1_text_color = tft_1.color565(red_val, green_val, blue_val);

  tft_1.setCursor(59, 36); tft_1.setTextColor(tft_1_text_color);  tft_1.setTextSize(4);  tft_1.println("GPU-T");
  tft_1.setCursor(96, 184); tft_1.setTextColor(tft_1_text_color);  tft_1.setTextSize(4);  tft_1.println("^C");
  tft_1.setCursor(40, 98); tft_1.setTextSize(7);

  switch (text_colour) {
    case 1: //green
      red_val = 0;
      green_val = 255 / brightness_divisor;
      blue_val = 0;
      tft_1_text_color = tft_1.color565(red_val, green_val, blue_val);

      tft_1.setTextColor(tft_1_text_color, GC9A01A_BLACK);
      tft_1.drawCircle(120, 120, 119, tft_1_text_color);
      tft_1.drawCircle(120, 120, 118, tft_1_text_color);
      tft_1.drawCircle(120, 120, 117, tft_1_text_color);
      break;
    case 2: //yellow
      red_val = 255 / brightness_divisor;
      green_val = 255 / brightness_divisor;
      blue_val = 0;
      tft_1_text_color = tft_1.color565(red_val, green_val, blue_val);

      tft_1.setTextColor(tft_1_text_color, GC9A01A_BLACK);
      tft_1.drawCircle(120, 120, 119, tft_1_text_color);
      tft_1.drawCircle(120, 120, 118, tft_1_text_color);
      tft_1.drawCircle(120, 120, 117, tft_1_text_color);
      break;
    case 3: //orange
      red_val = 255 / brightness_divisor;
      green_val = 165 / brightness_divisor;
      blue_val = 0;
      tft_1_text_color = tft_1.color565(red_val, green_val, blue_val);

      tft_1.setTextColor(tft_1_text_color, GC9A01A_BLACK);
      tft_1.drawCircle(120, 120, 119, tft_1_text_color);
      tft_1.drawCircle(120, 120, 118, tft_1_text_color);
      tft_1.drawCircle(120, 120, 117, tft_1_text_color);
      break;
    case 4: //red
      red_val = 255 / brightness_divisor;
      green_val = 0;
      blue_val = 0;
      tft_1_text_color = tft_1.color565(red_val, green_val, blue_val);

      tft_1.setTextColor(tft_1_text_color, GC9A01A_BLACK);
      tft_1.drawCircle(120, 120, 119, tft_1_text_color);
      tft_1.drawCircle(120, 120, 118, tft_1_text_color);
      tft_1.drawCircle(120, 120, 117, tft_1_text_color);
      break;
    default://blue
      red_val = 0;
      green_val = 0;
      blue_val = 255 / brightness_divisor;
      tft_1_text_color = tft_1.color565(red_val, green_val, blue_val);

      tft_1.setTextColor(tft_1_text_color, GC9A01A_BLACK);
      tft_1.drawCircle(120, 120, 119, tft_1_text_color);
      tft_1.drawCircle(120, 120, 118, tft_1_text_color);
      tft_1.drawCircle(120, 120, 117, tft_1_text_color);
      break;
  }

  tft_1.println(temp_val);
  prev_gpu_temp_val = temp_val;
  yield();
}

/*=====================================================================================================================================================*/

void show_cpu_load_val_tft_1(String load_val, int text_colour) {

  uint16_t red_val, green_val, blue_val, tft_1_text_color;
  red_val = 254 / brightness_divisor;
  green_val = 255 / brightness_divisor;
  blue_val = 254 / brightness_divisor;
  tft_1_text_color = tft_1.color565(red_val, green_val, blue_val);

  tft_1.setCursor(62, 36); tft_1.setTextColor(tft_1_text_color);  tft_1.setTextSize(4);  tft_1.println("CPU-L");
  tft_1.setCursor(110, 184); tft_1.setTextColor(tft_1_text_color);  tft_1.setTextSize(4);  tft_1.println("%");
  tft_1.setCursor(40, 98); tft_1.setTextSize(7);

  switch (text_colour) {
    case 1: //green
      red_val = 0;
      green_val = 255 / brightness_divisor;
      blue_val = 0;
      tft_1_text_color = tft_1.color565(red_val, green_val, blue_val);

      tft_1.setTextColor(tft_1_text_color, GC9A01A_BLACK);
      tft_1.drawCircle(120, 120, 119, tft_1_text_color);
      tft_1.drawCircle(120, 120, 118, tft_1_text_color);
      tft_1.drawCircle(120, 120, 117, tft_1_text_color);
      break;
    case 2: //yellow
      red_val = 255 / brightness_divisor;
      green_val = 255 / brightness_divisor;
      blue_val = 0;
      tft_1_text_color = tft_1.color565(red_val, green_val, blue_val);

      tft_1.setTextColor(tft_1_text_color, GC9A01A_BLACK);
      tft_1.drawCircle(120, 120, 119, tft_1_text_color);
      tft_1.drawCircle(120, 120, 118, tft_1_text_color);
      tft_1.drawCircle(120, 120, 117, tft_1_text_color);
      break;
    case 3: //orange
      red_val = 255 / brightness_divisor;
      green_val = 165 / brightness_divisor;
      blue_val = 0;
      tft_1_text_color = tft_1.color565(red_val, green_val, blue_val);

      tft_1.setTextColor(tft_1_text_color, GC9A01A_BLACK);
      tft_1.drawCircle(120, 120, 119, tft_1_text_color);
      tft_1.drawCircle(120, 120, 118, tft_1_text_color);
      tft_1.drawCircle(120, 120, 117, tft_1_text_color);
      break;
    case 4: //red
      red_val = 255 / brightness_divisor;
      green_val = 0;
      blue_val = 0;
      tft_1_text_color = tft_1.color565(red_val, green_val, blue_val);

      tft_1.setTextColor(tft_1_text_color, GC9A01A_BLACK);
      tft_1.drawCircle(120, 120, 119, tft_1_text_color);
      tft_1.drawCircle(120, 120, 118, tft_1_text_color);
      tft_1.drawCircle(120, 120, 117, tft_1_text_color);
      break;
    default://blue
      red_val = 0;
      green_val = 0;
      blue_val = 255 / brightness_divisor;
      tft_1_text_color = tft_1.color565(red_val, green_val, blue_val);

      tft_1.setTextColor(tft_1_text_color, GC9A01A_BLACK);
      tft_1.drawCircle(120, 120, 119, tft_1_text_color);
      tft_1.drawCircle(120, 120, 118, tft_1_text_color);
      tft_1.drawCircle(120, 120, 117, tft_1_text_color);
      break;
  }

  tft_1.println(load_val);
  prev_cpu_load_val = load_val;
  yield();
}

void show_gpu_load_val_tft_1(String load_val, int text_colour) {
  uint16_t red_val, green_val, blue_val, tft_1_text_color;
  red_val = 254 / brightness_divisor;
  green_val = 255 / brightness_divisor;
  blue_val = 254 / brightness_divisor;
  tft_1_text_color = tft_1.color565(red_val, green_val, blue_val);

  tft_1.setCursor(62, 36); tft_1.setTextColor(tft_1_text_color);  tft_1.setTextSize(4);  tft_1.println("GPU-L");
  tft_1.setCursor(110, 184); tft_1.setTextColor(tft_1_text_color);  tft_1.setTextSize(4);  tft_1.println("%");
  tft_1.setCursor(40, 98); tft_1.setTextSize(7);

  switch (text_colour) {
    case 1: //green
      red_val = 0;
      green_val = 255 / brightness_divisor;
      blue_val = 0;
      tft_1_text_color = tft_1.color565(red_val, green_val, blue_val);

      tft_1.setTextColor(tft_1_text_color, GC9A01A_BLACK);
      tft_1.drawCircle(120, 120, 119, tft_1_text_color);
      tft_1.drawCircle(120, 120, 118, tft_1_text_color);
      tft_1.drawCircle(120, 120, 117, tft_1_text_color);
      break;
    case 2: //yellow
      red_val = 255 / brightness_divisor;
      green_val = 255 / brightness_divisor;
      blue_val = 0;
      tft_1_text_color = tft_1.color565(red_val, green_val, blue_val);

      tft_1.setTextColor(tft_1_text_color, GC9A01A_BLACK);
      tft_1.drawCircle(120, 120, 119, tft_1_text_color);
      tft_1.drawCircle(120, 120, 118, tft_1_text_color);
      tft_1.drawCircle(120, 120, 117, tft_1_text_color);
      break;
    case 3: //orange
      red_val = 255 / brightness_divisor;
      green_val = 165 / brightness_divisor;
      blue_val = 0;
      tft_1_text_color = tft_1.color565(red_val, green_val, blue_val);

      tft_1.setTextColor(tft_1_text_color, GC9A01A_BLACK);
      tft_1.drawCircle(120, 120, 119, tft_1_text_color);
      tft_1.drawCircle(120, 120, 118, tft_1_text_color);
      tft_1.drawCircle(120, 120, 117, tft_1_text_color);
      break;
    case 4: //red
      red_val = 255 / brightness_divisor;
      green_val = 0;
      blue_val = 0;
      tft_1_text_color = tft_1.color565(red_val, green_val, blue_val);

      tft_1.setTextColor(tft_1_text_color, GC9A01A_BLACK);
      tft_1.drawCircle(120, 120, 119, tft_1_text_color);
      tft_1.drawCircle(120, 120, 118, tft_1_text_color);
      tft_1.drawCircle(120, 120, 117, tft_1_text_color);
      break;
    default://blue
      red_val = 0;
      green_val = 0;
      blue_val = 255 / brightness_divisor;
      tft_1_text_color = tft_1.color565(red_val, green_val, blue_val);

      tft_1.setTextColor(tft_1_text_color, GC9A01A_BLACK);
      tft_1.drawCircle(120, 120, 119, tft_1_text_color);
      tft_1.drawCircle(120, 120, 118, tft_1_text_color);
      tft_1.drawCircle(120, 120, 117, tft_1_text_color);
      break;
  }

  tft_1.println(load_val);
  prev_gpu_load_val = load_val;
  yield();
}
