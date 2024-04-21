void init_buttons() {
  pinMode(exit_serial_switch, INPUT_PULLUP);
  pinMode(brightness_divisor_button, INPUT_PULLDOWN);
  pinMode(tft_1_UI_button, INPUT_PULLDOWN);
  pinMode(tft_2_UI_button, INPUT_PULLDOWN);
}

void poll_exit_switch() {
  //if this switch is set to LOW, it'll exit the desktop app and reset the board
  if (digitalRead(exit_serial_switch) == LOW) {
    unsigned long time_now = millis();
    while (millis() - time_now < 20000) {
      exit_serial();
      delay(10);
    }
  }
}

void poll_brightness_divisor_button() {
  //if this button is pressed, it'll increment brightness_divisor_array_current_element by 1
  if (digitalRead(brightness_divisor_button) == HIGH) {
    delay(200); //debounce time
    brightness_divisor_array_current_element += 1;
    if (brightness_divisor_array_current_element >= brightness_divisor_array_size) {
      brightness_divisor_array_current_element = 0;
    }
    tft_1_bg_drawn = false;
    tft_2_bg_drawn = false;
    brightness_divisor = brightness_divisor_array[brightness_divisor_array_current_element];
  }
}

void poll_tft_UI_buttons() {
  if (digitalRead(tft_1_UI_button) == HIGH) {
    delay(200);
    tft_1_UI_page += 1;
    if (tft_1_UI_page > tft_UI_pages) {
      tft_1_UI_page = 1;
    }
  }
  if (digitalRead(tft_2_UI_button) == HIGH) {
    delay(200);
    tft_2_UI_page += 1;
    if (tft_2_UI_page > tft_UI_pages) {
      tft_2_UI_page = 1;
    }
  }
}

void poll_buttons_and_switches() {
  poll_exit_switch();
  poll_brightness_divisor_button();
  poll_tft_UI_buttons();
}
