void show_day_and_date_tft_2_bg_1(String day_val, String date_val) {
  uint16_t red_val, green_val, blue_val, tft_2_text_color, tft_2_text_bg_color, tft_2_bmp_color;
  red_val = 198 / brightness_divisor;
  green_val = 195 / brightness_divisor;
  blue_val = 198 / brightness_divisor;
  tft_2_text_color = tft_2.color565(red_val, green_val, blue_val); //light grey

  red_val = 0 / brightness_divisor;
  green_val = 125 / brightness_divisor;
  blue_val = 123 / brightness_divisor;
  tft_2_text_bg_color = tft_2.color565(red_val, green_val, blue_val); //dark cyan

  red_val = 254 / brightness_divisor;
  green_val = 255 / brightness_divisor;
  blue_val = 254 / brightness_divisor;
  tft_2_bmp_color = tft_2.color565(red_val, green_val, blue_val); //dark grey

  if (tft_2_bg_drawn == false) {
    tft_2.fillScreen(GC9A01A_BLACK);
    canvas_1.fillScreen(0);
    canvas_3.fillScreen(0);
    tft_2.drawBitmap(0, 0, clock_bg1 , 240, 240, tft_2_bmp_color, GC9A01A_BLACK);
    tft_2_bg_drawn = true;
    prev_date_val_2 = "";
    prev_day_val_2 = "";
  }

  if (prev_date_val_2 != date_val || prev_day_val_2 != day_val) {
    canvas_1.drawBitmap(0, -70, clock_bg1 , 240, 240, tft_2_text_bg_color, GC9A01A_BLACK);
    canvas_1.setCursor(42, 9); canvas_1.setTextColor(tft_2_text_color); canvas_1.setTextSize(3); canvas_1.print(day_val);
    canvas_3.drawBitmap(0, -140, clock_bg1 , 240, 240, tft_2_text_bg_color, GC9A01A_BLACK);
    canvas_3.setCursor(34, 9); canvas_3.setTextColor(tft_2_text_color); canvas_3.setTextSize(3); canvas_3.print(date_val);
    tft_2.drawRGBBitmap(0, 70, canvas_1.getBuffer(), canvas_1.width(), canvas_1.height());
    tft_2.drawRGBBitmap(0, 140, canvas_3.getBuffer(), canvas_3.width(), canvas_3.height());
  }
  prev_date_val_2 = date_val;
  prev_day_val_2 = day_val;
}

void show_day_and_date_tft_2_bg_2(String day_val, String date_val) {
  uint16_t red_val, green_val, blue_val, tft_2_text_color, tft_2_text_bg_color, tft_2_bmp_color;
  red_val = 198 / brightness_divisor;
  green_val = 195 / brightness_divisor;
  blue_val = 198 / brightness_divisor;
  tft_2_text_color = tft_2.color565(red_val, green_val, blue_val); //light grey

  red_val = 0 / brightness_divisor;
  green_val = 125 / brightness_divisor;
  blue_val = 123 / brightness_divisor;
  tft_2_text_bg_color = tft_2.color565(red_val, green_val, blue_val); //dark cyan

  red_val = 254 / brightness_divisor;
  green_val = 255 / brightness_divisor;
  blue_val = 254 / brightness_divisor;
  tft_2_bmp_color = tft_2.color565(red_val, green_val, blue_val); //dark grey

  if (tft_2_bg_drawn == false) {
    tft_2.fillScreen(GC9A01A_BLACK);
    canvas_1.fillScreen(0);
    canvas_3.fillScreen(0);
    tft_2.drawBitmap(0, 0, clock_bg2 , 240, 240, tft_2_bmp_color, GC9A01A_BLACK);
    tft_2_bg_drawn = true;
    prev_date_val_2 = "";
    prev_day_val_2 = "";
  }

  if (prev_date_val_2 != date_val || prev_day_val_2 != day_val) {
    canvas_1.drawBitmap(0, -70, clock_bg2 , 240, 240, tft_2_text_bg_color, GC9A01A_BLACK);
    canvas_1.setCursor(42, 9); canvas_1.setTextColor(tft_2_text_color); canvas_1.setTextSize(3); canvas_1.print(day_val);
    canvas_3.drawBitmap(0, -140, clock_bg2 , 240, 240, tft_2_text_bg_color, GC9A01A_BLACK);
    canvas_3.setCursor(34, 9); canvas_3.setTextColor(tft_2_text_color); canvas_3.setTextSize(3); canvas_3.print(date_val);
    tft_2.drawRGBBitmap(0, 70, canvas_1.getBuffer(), canvas_1.width(), canvas_1.height());
    tft_2.drawRGBBitmap(0, 140, canvas_3.getBuffer(), canvas_3.width(), canvas_3.height());
  }
  prev_date_val_2 = date_val;
  prev_day_val_2 = day_val;
}

void show_time_tft_2_bg_1(String time_val) {
  uint16_t red_val, green_val, blue_val, tft_2_text_color, tft_2_text_bg_color, tft_2_bmp_color;
  red_val = 198 / brightness_divisor;
  green_val = 195 / brightness_divisor;
  blue_val = 198 / brightness_divisor;
  tft_2_text_color = tft_2.color565(red_val, green_val, blue_val); //light grey

  red_val = 0 / brightness_divisor;
  green_val = 125 / brightness_divisor;
  blue_val = 123 / brightness_divisor;
  tft_2_text_bg_color = tft_2.color565(red_val, green_val, blue_val); //dark cyan

  red_val = 254 / brightness_divisor;
  green_val = 255 / brightness_divisor;
  blue_val = 254 / brightness_divisor;
  tft_2_bmp_color = tft_2.color565(red_val, green_val, blue_val); //dark grey

  if (tft_2_bg_drawn == false) {
    tft_2.fillScreen(GC9A01A_BLACK);
    canvas_2.fillScreen(0);
    tft_2.drawBitmap(0, 0, clock_bg1 , 240, 240, tft_2_bmp_color, GC9A01A_BLACK);
    tft_2_bg_drawn = true;
    prev_time_val_2 = "";
  }
  if (prev_time_val_2 != time_val) {
    canvas_2.drawBitmap(0, -140, clock_bg1 , 240, 240, tft_2_text_bg_color, GC9A01A_BLACK);
    canvas_2.setCursor(40, 5); canvas_2.setTextColor(tft_2_text_color); canvas_2.setTextSize(4); canvas_2.print(time_val);
    tft_2.drawRGBBitmap(0, 140, canvas_2.getBuffer(), canvas_2.width(), canvas_2.height());
  }
  prev_time_val_2 = time_val;
}

void show_time_tft_2_bg_2(String time_val) {
  uint16_t red_val, green_val, blue_val, tft_2_text_color, tft_2_text_bg_color, tft_2_bmp_color;
  red_val = 198 / brightness_divisor;
  green_val = 195 / brightness_divisor;
  blue_val = 198 / brightness_divisor;
  tft_2_text_color = tft_2.color565(red_val, green_val, blue_val); //light grey

  red_val = 0 / brightness_divisor;
  green_val = 125 / brightness_divisor;
  blue_val = 123 / brightness_divisor;
  tft_2_text_bg_color = tft_2.color565(red_val, green_val, blue_val); //dark cyan

  red_val = 254 / brightness_divisor;
  green_val = 255 / brightness_divisor;
  blue_val = 254 / brightness_divisor;
  tft_2_bmp_color = tft_2.color565(red_val, green_val, blue_val); //dark grey

  if (tft_2_bg_drawn == false) {
    tft_2.fillScreen(GC9A01A_BLACK);
    canvas_2.fillScreen(0);
    tft_2.drawBitmap(0, 0, clock_bg2 , 240, 240, tft_2_bmp_color, GC9A01A_BLACK);
    tft_2_bg_drawn = true;
    prev_time_val_2 = "";
  }
  if (prev_time_val_2 != time_val) {
    canvas_2.drawBitmap(0, -140, clock_bg2 , 240, 240, tft_2_text_bg_color, GC9A01A_BLACK);
    canvas_2.setCursor(40, 5); canvas_2.setTextColor(tft_2_text_color); canvas_2.setTextSize(4); canvas_2.print(time_val);
    tft_2.drawRGBBitmap(0, 140, canvas_2.getBuffer(), canvas_2.width(), canvas_2.height());
  }
  prev_time_val_2 = time_val;
}

void show_cpu_temp_and_load_val_tft_2(String temp_val, String load_val, int temp_text_color, int load_text_color) {
  uint16_t red_val_L, green_val_L, blue_val_L, red_val_R, green_val_R, blue_val_R, canvasL_2_text_color, canvasR_2_text_color, canvasL_2_w_text_color, canvasR_2_w_text_color;

  canvasL_2.setCursor(16, 112);
  switch (temp_text_color) {
    case 1: //green
      red_val_L = 0;
      green_val_L = 255 / brightness_divisor;
      blue_val_L = 0;
      canvasL_2_text_color = tft_2.color565(red_val_L, green_val_L, blue_val_L);

      canvasL_2.setTextColor(canvasL_2_text_color, GC9A01A_BLACK);
      canvasL_2.drawCircle(120, 120, 119, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 118, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 117, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 116, canvasL_2_text_color);
      break;
    case 2: //yellow
      red_val_L = 255 / brightness_divisor;
      green_val_L = 255 / brightness_divisor;
      blue_val_L = 0;
      canvasL_2_text_color = tft_2.color565(red_val_L, green_val_L, blue_val_L);

      canvasL_2.setTextColor(canvasL_2_text_color, GC9A01A_BLACK);
      canvasL_2.drawCircle(120, 120, 119, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 118, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 117, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 116, canvasL_2_text_color);
      break;
    case 3: //orange
      red_val_L = 255 / brightness_divisor;
      green_val_L = 165 / brightness_divisor;
      blue_val_L = 0;
      canvasL_2_text_color = tft_2.color565(red_val_L, green_val_L, blue_val_L);

      canvasL_2.setTextColor(canvasL_2_text_color, GC9A01A_BLACK);
      canvasL_2.drawCircle(120, 120, 119, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 118, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 117, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 116, canvasL_2_text_color);
      break;
    case 4: //red
      red_val_L = 255 / brightness_divisor;
      green_val_L = 0;
      blue_val_L = 0;
      canvasL_2_text_color = tft_2.color565(red_val_L, green_val_L, blue_val_L);

      canvasL_2.setTextColor(canvasL_2_text_color, GC9A01A_BLACK);
      canvasL_2.drawCircle(120, 120, 119, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 118, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 117, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 116, canvasL_2_text_color);
      break;
    default://blue
      red_val_L = 0;
      green_val_L = 0;
      blue_val_L = 255 / brightness_divisor;
      canvasL_2_text_color = tft_2.color565(red_val_L, green_val_L, blue_val_L);

      canvasL_2.setTextColor(canvasL_2_text_color, GC9A01A_BLACK);
      canvasL_2.drawCircle(120, 120, 119, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 118, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 117, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 116, canvasL_2_text_color);
      break;
  }
  canvasL_2.setTextSize(4); canvasL_2.print(temp_val);
  yield();

  canvasR_2.setCursor(13, 112);
  switch (load_text_color) {
    case 1: //green
      red_val_R = 0;
      green_val_R = 255 / brightness_divisor;
      blue_val_R = 0;
      canvasR_2_text_color = tft_2.color565(red_val_R, green_val_R, blue_val_R);

      canvasR_2.setTextColor(canvasR_2_text_color, GC9A01A_BLACK);
      canvasR_2.drawCircle(0, 120, 119, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 118, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 117, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 116, canvasR_2_text_color);
      break;
    case 2: //yellow
      red_val_R = 255 / brightness_divisor;
      green_val_R = 255 / brightness_divisor;
      blue_val_R = 0;
      canvasR_2_text_color = tft_2.color565(red_val_R, green_val_R, blue_val_R);

      canvasR_2.setTextColor(canvasR_2_text_color, GC9A01A_BLACK);
      canvasR_2.drawCircle(0, 120, 119, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 118, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 117, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 116, canvasR_2_text_color);
      break;
    case 3: //orange
      red_val_R = 255 / brightness_divisor;
      green_val_R = 165 / brightness_divisor;
      blue_val_R = 0;
      canvasR_2_text_color = tft_2.color565(red_val_R, green_val_R, blue_val_R);

      canvasR_2.setTextColor(canvasR_2_text_color, GC9A01A_BLACK);
      canvasR_2.drawCircle(0, 120, 119, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 118, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 117, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 116, canvasR_2_text_color);
      break;
    case 4: //red
      red_val_R = 255 / brightness_divisor;
      green_val_R = 0;
      blue_val_R = 0;
      canvasR_2_text_color = tft_2.color565(red_val_R, green_val_R, blue_val_R);

      canvasR_2.setTextColor(canvasR_2_text_color, GC9A01A_BLACK);
      canvasR_2.drawCircle(0, 120, 119, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 118, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 117, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 116, canvasR_2_text_color);
      break;
    default://blue
      red_val_R = 0;
      green_val_R = 0;
      blue_val_R = 255 / brightness_divisor;
      canvasR_2_text_color = tft_2.color565(red_val_R, green_val_R, blue_val_R);

      canvasR_2.setTextColor(canvasR_2_text_color, GC9A01A_BLACK);
      canvasR_2.drawCircle(0, 120, 119, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 118, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 117, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 116, canvasR_2_text_color);
      break;
  }
  canvasR_2.setTextSize(4); canvasR_2.print(load_val);
  yield();

  //start of GUI layout
  red_val_L = 254 / brightness_divisor;
  green_val_L = 255 / brightness_divisor;
  blue_val_L = 254 / brightness_divisor;
  canvasL_2_w_text_color = tft_2.color565(red_val_L, green_val_L, blue_val_L);

  red_val_R = 254 / brightness_divisor;
  green_val_R = 255 / brightness_divisor;
  blue_val_R = 254 / brightness_divisor;
  canvasR_2_w_text_color = tft_2.color565(red_val_R, green_val_R, blue_val_R);

  //vertical white separator rectangles
  canvasL_2.fillRect(118, 50, 2, 240, canvasL_2_w_text_color);
  canvasR_2.fillRect(120, 50, 4, 240, canvasR_2_w_text_color);
  //horizontal black top and bottom bars
  canvasL_2.fillRect(0, 0, 240, 50, 0x0000); canvasR_2.fillRect(0, 0, 240, 50, 0x0000); //top
  canvasL_2.fillRect(0, 210, 240, 30, 0x0000); canvasR_2.fillRect(0, 210, 240, 30, 0x0000); //bottom
  //horizontal white separator rectangles
  canvasL_2.fillRect(27, 48, 120, 2, canvasL_2_w_text_color); canvasR_2.fillRect(0, 48, 94, 2, canvasR_2_w_text_color);

  canvasL_2.setCursor(83, 12); canvasL_2.setTextColor(canvasL_2_w_text_color, GC9A01A_BLACK); canvasL_2.setTextSize(4); canvasL_2.print("CPU");
  canvasR_2.setCursor(-34, 12); canvasR_2.setTextColor(canvasR_2_w_text_color, GC9A01A_BLACK); canvasR_2.setTextSize(4); canvasR_2.print("CPU");
  canvasL_2.setCursor(62, 60); canvasL_2.setTextColor(canvasL_2_w_text_color, GC9A01A_BLACK); canvasL_2.setTextSize(3); canvasL_2.print("T");
  canvasR_2.setCursor(43, 60); canvasR_2.setTextColor(canvasR_2_w_text_color, GC9A01A_BLACK); canvasR_2.setTextSize(3); canvasR_2.print("L");
  canvasL_2.setCursor(51, 175); canvasL_2.setTextColor(canvasL_2_w_text_color, GC9A01A_BLACK); canvasL_2.setTextSize(3); canvasL_2.print("^C");
  canvasR_2.setCursor(43, 175); canvasR_2.setTextColor(canvasR_2_w_text_color, GC9A01A_BLACK); canvasR_2.setTextSize(3); canvasR_2.print("%");
  //end of GUI layout
  yield();
  tft_2.drawRGBBitmap(0, 0, canvasL_2.getBuffer(), canvasL_2.width(), canvasL_2.height());
  tft_2.drawRGBBitmap(120, 0, canvasR_2.getBuffer(), canvasR_2.width(), canvasR_2.height());
  yield();
  prev_cpu_temp_val = temp_val;
  prev_cpu_load_val = load_val;
}

void show_gpu_temp_and_load_val_tft_2(String temp_val, String load_val, int temp_text_color, int load_text_color) {
  uint16_t red_val_L, green_val_L, blue_val_L, red_val_R, green_val_R, blue_val_R, canvasL_2_text_color, canvasR_2_text_color, canvasL_2_w_text_color, canvasR_2_w_text_color;

  canvasL_2.setCursor(16, 112);
  switch (temp_text_color) {
    case 1: //green
      red_val_L = 0;
      green_val_L = 255 / brightness_divisor;
      blue_val_L = 0;
      canvasL_2_text_color = tft_2.color565(red_val_L, green_val_L, blue_val_L);

      canvasL_2.setTextColor(canvasL_2_text_color, GC9A01A_BLACK);
      canvasL_2.drawCircle(120, 120, 119, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 118, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 117, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 116, canvasL_2_text_color);
      break;
    case 2: //yellow
      red_val_L = 255 / brightness_divisor;
      green_val_L = 255 / brightness_divisor;
      blue_val_L = 0;
      canvasL_2_text_color = tft_2.color565(red_val_L, green_val_L, blue_val_L);

      canvasL_2.setTextColor(canvasL_2_text_color, GC9A01A_BLACK);
      canvasL_2.drawCircle(120, 120, 119, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 118, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 117, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 116, canvasL_2_text_color);
      break;
    case 3: //orange
      red_val_L = 255 / brightness_divisor;
      green_val_L = 165 / brightness_divisor;
      blue_val_L = 0;
      canvasL_2_text_color = tft_2.color565(red_val_L, green_val_L, blue_val_L);

      canvasL_2.setTextColor(canvasL_2_text_color, GC9A01A_BLACK);
      canvasL_2.drawCircle(120, 120, 119, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 118, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 117, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 116, canvasL_2_text_color);
      break;
    case 4: //red
      red_val_L = 255 / brightness_divisor;
      green_val_L = 0;
      blue_val_L = 0;
      canvasL_2_text_color = tft_2.color565(red_val_L, green_val_L, blue_val_L);

      canvasL_2.setTextColor(canvasL_2_text_color, GC9A01A_BLACK);
      canvasL_2.drawCircle(120, 120, 119, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 118, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 117, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 116, canvasL_2_text_color);
      break;
    default://blue
      red_val_L = 0;
      green_val_L = 0;
      blue_val_L = 255 / brightness_divisor;
      canvasL_2_text_color = tft_2.color565(red_val_L, green_val_L, blue_val_L);

      canvasL_2.setTextColor(canvasL_2_text_color, GC9A01A_BLACK);
      canvasL_2.drawCircle(120, 120, 119, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 118, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 117, canvasL_2_text_color);
      canvasL_2.drawCircle(120, 120, 116, canvasL_2_text_color);
      break;
  }
  canvasL_2.setTextSize(4); canvasL_2.print(temp_val);
  yield();

  canvasR_2.setCursor(13, 112);
  switch (load_text_color) {
    case 1: //green
      red_val_R = 0;
      green_val_R = 255 / brightness_divisor;
      blue_val_R = 0;
      canvasR_2_text_color = tft_2.color565(red_val_R, green_val_R, blue_val_R);

      canvasR_2.setTextColor(canvasR_2_text_color, GC9A01A_BLACK);
      canvasR_2.drawCircle(0, 120, 119, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 118, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 117, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 116, canvasR_2_text_color);
      break;
    case 2: //yellow
      red_val_R = 255 / brightness_divisor;
      green_val_R = 255 / brightness_divisor;
      blue_val_R = 0;
      canvasR_2_text_color = tft_2.color565(red_val_R, green_val_R, blue_val_R);

      canvasR_2.setTextColor(canvasR_2_text_color, GC9A01A_BLACK);
      canvasR_2.drawCircle(0, 120, 119, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 118, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 117, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 116, canvasR_2_text_color);
      break;
    case 3: //orange
      red_val_R = 255 / brightness_divisor;
      green_val_R = 165 / brightness_divisor;
      blue_val_R = 0;
      canvasR_2_text_color = tft_2.color565(red_val_R, green_val_R, blue_val_R);

      canvasR_2.setTextColor(canvasR_2_text_color, GC9A01A_BLACK);
      canvasR_2.drawCircle(0, 120, 119, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 118, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 117, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 116, canvasR_2_text_color);
      break;
    case 4: //red
      red_val_R = 255 / brightness_divisor;
      green_val_R = 0;
      blue_val_R = 0;
      canvasR_2_text_color = tft_2.color565(red_val_R, green_val_R, blue_val_R);

      canvasR_2.setTextColor(canvasR_2_text_color, GC9A01A_BLACK);
      canvasR_2.drawCircle(0, 120, 119, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 118, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 117, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 116, canvasR_2_text_color);
      break;
    default://blue
      red_val_R = 0;
      green_val_R = 0;
      blue_val_R = 255 / brightness_divisor;
      canvasR_2_text_color = tft_2.color565(red_val_R, green_val_R, blue_val_R);

      canvasR_2.setTextColor(canvasR_2_text_color, GC9A01A_BLACK);
      canvasR_2.drawCircle(0, 120, 119, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 118, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 117, canvasR_2_text_color);
      canvasR_2.drawCircle(0, 120, 116, canvasR_2_text_color);
      break;
  }
  canvasR_2.setTextSize(4); canvasR_2.print(load_val);
  yield();

  //start of GUI layout
  red_val_L = 254 / brightness_divisor;
  green_val_L = 255 / brightness_divisor;
  blue_val_L = 254 / brightness_divisor;
  canvasL_2_w_text_color = tft_2.color565(red_val_L, green_val_L, blue_val_L);

  red_val_R = 254 / brightness_divisor;
  green_val_R = 255 / brightness_divisor;
  blue_val_R = 254 / brightness_divisor;
  canvasR_2_w_text_color = tft_2.color565(red_val_R, green_val_R, blue_val_R);

  //vertical white separator rectangles
  canvasL_2.fillRect(118, 50, 2, 240, canvasL_2_w_text_color);
  canvasR_2.fillRect(120, 50, 4, 240, canvasR_2_w_text_color);
  //horizontal black top and bottom bars
  canvasL_2.fillRect(0, 0, 240, 50, 0x0000); canvasR_2.fillRect(0, 0, 240, 50, 0x0000); //top
  canvasL_2.fillRect(0, 210, 240, 30, 0x0000); canvasR_2.fillRect(0, 210, 240, 30, 0x0000); //bottom
  //horizontal white separator rectangles
  canvasL_2.fillRect(27, 48, 120, 2, canvasL_2_w_text_color); canvasR_2.fillRect(0, 48, 94, 2, canvasR_2_w_text_color);

  canvasL_2.setCursor(83, 12); canvasL_2.setTextColor(canvasL_2_w_text_color, GC9A01A_BLACK); canvasL_2.setTextSize(4); canvasL_2.print("GPU");
  canvasR_2.setCursor(-34, 12); canvasR_2.setTextColor(canvasR_2_w_text_color, GC9A01A_BLACK); canvasR_2.setTextSize(4); canvasR_2.print("GPU");
  canvasL_2.setCursor(62, 60); canvasL_2.setTextColor(canvasL_2_w_text_color, GC9A01A_BLACK); canvasL_2.setTextSize(3); canvasL_2.print("T");
  canvasR_2.setCursor(43, 60); canvasR_2.setTextColor(canvasR_2_w_text_color, GC9A01A_BLACK); canvasR_2.setTextSize(3); canvasR_2.print("L");
  canvasL_2.setCursor(51, 175); canvasL_2.setTextColor(canvasL_2_w_text_color, GC9A01A_BLACK); canvasL_2.setTextSize(3); canvasL_2.print("^C");
  canvasR_2.setCursor(43, 175); canvasR_2.setTextColor(canvasR_2_w_text_color, GC9A01A_BLACK); canvasR_2.setTextSize(3); canvasR_2.print("%");
  //end of GUI layout
  yield();
  tft_2.drawRGBBitmap(0, 0, canvasL_2.getBuffer(), canvasL_2.width(), canvasL_2.height());
  tft_2.drawRGBBitmap(120, 0, canvasR_2.getBuffer(), canvasR_2.width(), canvasR_2.height());
  yield();
  prev_gpu_temp_val = temp_val;
  prev_gpu_load_val = load_val;
}

void show_cpu_temp_val_tft_2(String temp_val, int text_colour) {

  uint16_t red_val, green_val, blue_val, tft_2_text_color;
  red_val = 254 / brightness_divisor;
  green_val = 255 / brightness_divisor;
  blue_val = 254 / brightness_divisor;
  tft_2_text_color = tft_2.color565(red_val, green_val, blue_val);

  tft_2.setCursor(59, 36); tft_2.setTextColor(tft_2_text_color);  tft_2.setTextSize(4);  tft_2.println("CPU-T");
  tft_2.setCursor(96, 184); tft_2.setTextColor(tft_2_text_color);  tft_2.setTextSize(4);  tft_2.println("^C");
  tft_2.setCursor(40, 98); tft_2.setTextSize(7);

  switch (text_colour) {
    case 1: //green
      red_val = 0;
      green_val = 255 / brightness_divisor;
      blue_val = 0;
      tft_2_text_color = tft_2.color565(red_val, green_val, blue_val);

      tft_2.setTextColor(tft_2_text_color, GC9A01A_BLACK);
      tft_2.drawCircle(120, 120, 119, tft_2_text_color);
      tft_2.drawCircle(120, 120, 118, tft_2_text_color);
      tft_2.drawCircle(120, 120, 117, tft_2_text_color);
      break;
    case 2: //yellow
      red_val = 255 / brightness_divisor;
      green_val = 255 / brightness_divisor;
      blue_val = 0;
      tft_2_text_color = tft_2.color565(red_val, green_val, blue_val);

      tft_2.setTextColor(tft_2_text_color, GC9A01A_BLACK);
      tft_2.drawCircle(120, 120, 119, tft_2_text_color);
      tft_2.drawCircle(120, 120, 118, tft_2_text_color);
      tft_2.drawCircle(120, 120, 117, tft_2_text_color);
      break;
    case 3: //orange
      red_val = 255 / brightness_divisor;
      green_val = 165 / brightness_divisor;
      blue_val = 0;
      tft_2_text_color = tft_2.color565(red_val, green_val, blue_val);

      tft_2.setTextColor(tft_2_text_color, GC9A01A_BLACK);
      tft_2.drawCircle(120, 120, 119, tft_2_text_color);
      tft_2.drawCircle(120, 120, 118, tft_2_text_color);
      tft_2.drawCircle(120, 120, 117, tft_2_text_color);
      break;
    case 4: //red
      red_val = 255 / brightness_divisor;
      green_val = 0;
      blue_val = 0;
      tft_2_text_color = tft_2.color565(red_val, green_val, blue_val);

      tft_2.setTextColor(tft_2_text_color, GC9A01A_BLACK);
      tft_2.drawCircle(120, 120, 119, tft_2_text_color);
      tft_2.drawCircle(120, 120, 118, tft_2_text_color);
      tft_2.drawCircle(120, 120, 117, tft_2_text_color);
      break;
    default://blue
      red_val = 0;
      green_val = 0;
      blue_val = 255 / brightness_divisor;
      tft_2_text_color = tft_2.color565(red_val, green_val, blue_val);

      tft_2.setTextColor(tft_2_text_color, GC9A01A_BLACK);
      tft_2.drawCircle(120, 120, 119, tft_2_text_color);
      tft_2.drawCircle(120, 120, 118, tft_2_text_color);
      tft_2.drawCircle(120, 120, 117, tft_2_text_color);
      break;
  }

  tft_2.println(temp_val);
  prev_cpu_temp_val = temp_val;
  yield();
}

void show_gpu_temp_val_tft_2(String temp_val, int text_colour) {
  uint16_t red_val, green_val, blue_val, tft_2_text_color;
  red_val = 254 / brightness_divisor;
  green_val = 255 / brightness_divisor;
  blue_val = 254 / brightness_divisor;
  tft_2_text_color = tft_2.color565(red_val, green_val, blue_val);

  tft_2.setCursor(59, 36); tft_2.setTextColor(tft_2_text_color);  tft_2.setTextSize(4);  tft_2.println("GPU-T");
  tft_2.setCursor(96, 184); tft_2.setTextColor(tft_2_text_color);  tft_2.setTextSize(4);  tft_2.println("^C");
  tft_2.setCursor(40, 98); tft_2.setTextSize(7);

  switch (text_colour) {
    case 1: //green
      red_val = 0;
      green_val = 255 / brightness_divisor;
      blue_val = 0;
      tft_2_text_color = tft_2.color565(red_val, green_val, blue_val);

      tft_2.setTextColor(tft_2_text_color, GC9A01A_BLACK);
      tft_2.drawCircle(120, 120, 119, tft_2_text_color);
      tft_2.drawCircle(120, 120, 118, tft_2_text_color);
      tft_2.drawCircle(120, 120, 117, tft_2_text_color);
      break;
    case 2: //yellow
      red_val = 255 / brightness_divisor;
      green_val = 255 / brightness_divisor;
      blue_val = 0;
      tft_2_text_color = tft_2.color565(red_val, green_val, blue_val);

      tft_2.setTextColor(tft_2_text_color, GC9A01A_BLACK);
      tft_2.drawCircle(120, 120, 119, tft_2_text_color);
      tft_2.drawCircle(120, 120, 118, tft_2_text_color);
      tft_2.drawCircle(120, 120, 117, tft_2_text_color);
      break;
    case 3: //orange
      red_val = 255 / brightness_divisor;
      green_val = 165 / brightness_divisor;
      blue_val = 0;
      tft_2_text_color = tft_2.color565(red_val, green_val, blue_val);

      tft_2.setTextColor(tft_2_text_color, GC9A01A_BLACK);
      tft_2.drawCircle(120, 120, 119, tft_2_text_color);
      tft_2.drawCircle(120, 120, 118, tft_2_text_color);
      tft_2.drawCircle(120, 120, 117, tft_2_text_color);
      break;
    case 4: //red
      red_val = 255 / brightness_divisor;
      green_val = 0;
      blue_val = 0;
      tft_2_text_color = tft_2.color565(red_val, green_val, blue_val);

      tft_2.setTextColor(tft_2_text_color, GC9A01A_BLACK);
      tft_2.drawCircle(120, 120, 119, tft_2_text_color);
      tft_2.drawCircle(120, 120, 118, tft_2_text_color);
      tft_2.drawCircle(120, 120, 117, tft_2_text_color);
      break;
    default://blue
      red_val = 0;
      green_val = 0;
      blue_val = 255 / brightness_divisor;
      tft_2_text_color = tft_2.color565(red_val, green_val, blue_val);

      tft_2.setTextColor(tft_2_text_color, GC9A01A_BLACK);
      tft_2.drawCircle(120, 120, 119, tft_2_text_color);
      tft_2.drawCircle(120, 120, 118, tft_2_text_color);
      tft_2.drawCircle(120, 120, 117, tft_2_text_color);
      break;
  }

  tft_2.println(temp_val);
  prev_gpu_temp_val = temp_val;
  yield();
}

/*=====================================================================================================================================================*/

void show_cpu_load_val_tft_2(String load_val, int text_colour) {

  uint16_t red_val, green_val, blue_val, tft_2_text_color;
  red_val = 254 / brightness_divisor;
  green_val = 255 / brightness_divisor;
  blue_val = 254 / brightness_divisor;
  tft_2_text_color = tft_2.color565(red_val, green_val, blue_val);

  tft_2.setCursor(62, 36); tft_2.setTextColor(tft_2_text_color);  tft_2.setTextSize(4);  tft_2.println("CPU-L");
  tft_2.setCursor(110, 184); tft_2.setTextColor(tft_2_text_color);  tft_2.setTextSize(4);  tft_2.println("%");
  tft_2.setCursor(40, 98); tft_2.setTextSize(7);

  switch (text_colour) {
    case 1: //green
      red_val = 0;
      green_val = 255 / brightness_divisor;
      blue_val = 0;
      tft_2_text_color = tft_2.color565(red_val, green_val, blue_val);

      tft_2.setTextColor(tft_2_text_color, GC9A01A_BLACK);
      tft_2.drawCircle(120, 120, 119, tft_2_text_color);
      tft_2.drawCircle(120, 120, 118, tft_2_text_color);
      tft_2.drawCircle(120, 120, 117, tft_2_text_color);
      break;
    case 2: //yellow
      red_val = 255 / brightness_divisor;
      green_val = 255 / brightness_divisor;
      blue_val = 0;
      tft_2_text_color = tft_2.color565(red_val, green_val, blue_val);

      tft_2.setTextColor(tft_2_text_color, GC9A01A_BLACK);
      tft_2.drawCircle(120, 120, 119, tft_2_text_color);
      tft_2.drawCircle(120, 120, 118, tft_2_text_color);
      tft_2.drawCircle(120, 120, 117, tft_2_text_color);
      break;
    case 3: //orange
      red_val = 255 / brightness_divisor;
      green_val = 165 / brightness_divisor;
      blue_val = 0;
      tft_2_text_color = tft_2.color565(red_val, green_val, blue_val);

      tft_2.setTextColor(tft_2_text_color, GC9A01A_BLACK);
      tft_2.drawCircle(120, 120, 119, tft_2_text_color);
      tft_2.drawCircle(120, 120, 118, tft_2_text_color);
      tft_2.drawCircle(120, 120, 117, tft_2_text_color);
      break;
    case 4: //red
      red_val = 255 / brightness_divisor;
      green_val = 0;
      blue_val = 0;
      tft_2_text_color = tft_2.color565(red_val, green_val, blue_val);

      tft_2.setTextColor(tft_2_text_color, GC9A01A_BLACK);
      tft_2.drawCircle(120, 120, 119, tft_2_text_color);
      tft_2.drawCircle(120, 120, 118, tft_2_text_color);
      tft_2.drawCircle(120, 120, 117, tft_2_text_color);
      break;
    default://blue
      red_val = 0;
      green_val = 0;
      blue_val = 255 / brightness_divisor;
      tft_2_text_color = tft_2.color565(red_val, green_val, blue_val);

      tft_2.setTextColor(tft_2_text_color);
      tft_2.drawCircle(120, 120, 119, tft_2_text_color);
      tft_2.drawCircle(120, 120, 118, tft_2_text_color);
      tft_2.drawCircle(120, 120, 117, tft_2_text_color);
      break;
  }

  tft_2.println(load_val);
  prev_cpu_load_val = load_val;
  yield();
}

void show_gpu_load_val_tft_2(String load_val, int text_colour) {
  uint16_t red_val, green_val, blue_val, tft_2_text_color;
  red_val = 254 / brightness_divisor;
  green_val = 255 / brightness_divisor;
  blue_val = 254 / brightness_divisor;
  tft_2_text_color = tft_2.color565(red_val, green_val, blue_val);

  tft_2.setCursor(62, 36); tft_2.setTextColor(tft_2_text_color);  tft_2.setTextSize(4);  tft_2.println("GPU-L");
  tft_2.setCursor(110, 184); tft_2.setTextColor(tft_2_text_color);  tft_2.setTextSize(4);  tft_2.println("%");
  tft_2.setCursor(40, 98); tft_2.setTextSize(7);

  switch (text_colour) {
    case 1: //green
      red_val = 0;
      green_val = 255 / brightness_divisor;
      blue_val = 0;
      tft_2_text_color = tft_2.color565(red_val, green_val, blue_val);

      tft_2.setTextColor(tft_2_text_color, GC9A01A_BLACK);
      tft_2.drawCircle(120, 120, 119, tft_2_text_color);
      tft_2.drawCircle(120, 120, 118, tft_2_text_color);
      tft_2.drawCircle(120, 120, 117, tft_2_text_color);
      break;
    case 2: //yellow
      red_val = 255 / brightness_divisor;
      green_val = 255 / brightness_divisor;
      blue_val = 0;
      tft_2_text_color = tft_2.color565(red_val, green_val, blue_val);

      tft_2.setTextColor(tft_2_text_color, GC9A01A_BLACK);
      tft_2.drawCircle(120, 120, 119, tft_2_text_color);
      tft_2.drawCircle(120, 120, 118, tft_2_text_color);
      tft_2.drawCircle(120, 120, 117, tft_2_text_color);
      break;
    case 3: //orange
      red_val = 255 / brightness_divisor;
      green_val = 165 / brightness_divisor;
      blue_val = 0;
      tft_2_text_color = tft_2.color565(red_val, green_val, blue_val);

      tft_2.setTextColor(tft_2_text_color, GC9A01A_BLACK);
      tft_2.drawCircle(120, 120, 119, tft_2_text_color);
      tft_2.drawCircle(120, 120, 118, tft_2_text_color);
      tft_2.drawCircle(120, 120, 117, tft_2_text_color);
      break;
    case 4: //red
      red_val = 255 / brightness_divisor;
      green_val = 0;
      blue_val = 0;
      tft_2_text_color = tft_2.color565(red_val, green_val, blue_val);

      tft_2.setTextColor(tft_2_text_color, GC9A01A_BLACK);
      tft_2.drawCircle(120, 120, 119, tft_2_text_color);
      tft_2.drawCircle(120, 120, 118, tft_2_text_color);
      tft_2.drawCircle(120, 120, 117, tft_2_text_color);
      break;
    default://blue
      red_val = 0;
      green_val = 0;
      blue_val = 255 / brightness_divisor;
      tft_2_text_color = tft_2.color565(red_val, green_val, blue_val);

      tft_2.setTextColor(tft_2_text_color, GC9A01A_BLACK);
      tft_2.drawCircle(120, 120, 119, tft_2_text_color);
      tft_2.drawCircle(120, 120, 118, tft_2_text_color);
      tft_2.drawCircle(120, 120, 117, tft_2_text_color);
      break;
  }

  tft_2.println(load_val);
  prev_gpu_load_val = load_val;
  yield();
}
