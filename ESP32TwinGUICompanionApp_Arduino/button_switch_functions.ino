void init_buttons() {
  pinMode(exit_serial_switch, INPUT_PULLUP);
  pinMode(brightness_divisor_button, INPUT_PULLDOWN);
  pinMode(tft_1_UI_button, INPUT_PULLDOWN);
  pinMode(tft_2_UI_button, INPUT_PULLDOWN);
}

void poll_exit_switch() {
  if (millis() - previous_end_poll > interval_end_poll) {
    if (digitalRead(exit_serial_switch) == LOW) {
      unsigned long time_now = millis();
      while (millis() - time_now < 120000) {
        exit_serial();
        delay(10);
      }
    }
  }
}

void poll_brightness_divisor_button() {
  //if this button is pressed, it'll increment brightness_divisor_array_current_element by 1

  brightness_divisor_button_currentState = digitalRead(brightness_divisor_button);
  bool change_detected = false;
  if (brightness_divisor_button_lastState == LOW && brightness_divisor_button_currentState == HIGH) {      // button is pressed
    brightness_divisor_button_pressedTime = millis();
  }
  else if (brightness_divisor_button_lastState == HIGH && brightness_divisor_button_currentState == LOW) { // button is released
    brightness_divisor_button_releasedTime = millis();
    long brightness_divisor_button_pressDuration = brightness_divisor_button_releasedTime - brightness_divisor_button_pressedTime;

    if ( brightness_divisor_button_pressDuration < SHORT_PRESS_TIME ) {
      change_detected = true;
      //Serial.println("A short press is detected");
      brightness_divisor_array_current_element += 1;
      if (brightness_divisor_array_current_element >= brightness_divisor_array_size) {
        brightness_divisor_array_current_element = 0;
      }
    }

    if ( brightness_divisor_button_pressDuration > LONG_PRESS_TIME ) {
      change_detected = true;
      //Serial.println("A long press is detected");
      brightness_divisor_array_current_element -= 1;
      if (brightness_divisor_array_current_element < 0) {
        brightness_divisor_array_current_element = brightness_divisor_array_size - 1;
      }
    }
  }
  brightness_divisor_button_lastState = brightness_divisor_button_currentState;

  if (change_detected) {
    writeFile(brightness_file_path, brightness_divisor_array_current_element);
    tft_1_bg_drawn = false;
    tft_2_bg_drawn = false;
    brightness_divisor = brightness_divisor_array[brightness_divisor_array_current_element];
    if (serial_begun) {
      tft_1_switch(prev_cpu_temp_val_1, prev_gpu_temp_val_1, prev_cpu_load_val_1, prev_gpu_load_val_1, prev_date_val_1, prev_time_val_1, prev_day_val_1);
      tft_2_switch(prev_cpu_temp_val_2, prev_gpu_temp_val_2, prev_cpu_load_val_2, prev_gpu_load_val_2, prev_date_val_2, prev_time_val_2, prev_day_val_2);
    }
  }


}

void poll_tft_UI_buttons() {
  tft_1_UI_button_currentState = digitalRead(tft_1_UI_button);

  if (tft_1_UI_button_lastState == LOW && tft_1_UI_button_currentState == HIGH) {      // button is pressed
    tft_1_UI_button_pressedTime = millis();
  }
  else if (tft_1_UI_button_lastState == HIGH && tft_1_UI_button_currentState == LOW) { // button is released
    tft_1_UI_button_releasedTime = millis();
    long tft_1_UI_button_pressDuration = tft_1_UI_button_releasedTime - tft_1_UI_button_pressedTime;

    if ( tft_1_UI_button_pressDuration < SHORT_PRESS_TIME ) {
      tft_1_change_detected = true;
      //Serial.println("A short press is detected");
      tft_1_UI_page += 1;
      if (tft_1_UI_page > tft_UI_pages) {
        tft_1_UI_page = 1;
      }
    }
    if ( tft_1_UI_button_pressDuration > LONG_PRESS_TIME ) {
      tft_1_change_detected = true;
      //Serial.println("A long press is detected");
      tft_1_UI_page -= 1;
      if ( tft_1_UI_page < 1) {
        tft_1_UI_page = tft_UI_pages;
      }
    }
  }
  //Serial.println(tft_1_UI_page);
  tft_1_UI_button_lastState = tft_1_UI_button_currentState;

  tft_2_UI_button_currentState = digitalRead(tft_2_UI_button);

  if (tft_2_UI_button_lastState == LOW && tft_2_UI_button_currentState == HIGH) {      // button is pressed
    tft_2_UI_button_pressedTime = millis();
  }
  else if (tft_2_UI_button_lastState == HIGH && tft_2_UI_button_currentState == LOW) { // button is released
    tft_2_UI_button_releasedTime = millis();
    long tft_2_UI_button_pressDuration = tft_2_UI_button_releasedTime - tft_2_UI_button_pressedTime;

    if ( tft_2_UI_button_pressDuration < SHORT_PRESS_TIME ) {
      tft_2_change_detected = true;
      //Serial.println("A short press is detected");
      tft_2_UI_page += 1;
      if (tft_2_UI_page > tft_UI_pages) {
        tft_2_UI_page = 1;
      }
    }
    if ( tft_2_UI_button_pressDuration > LONG_PRESS_TIME ) {
      tft_2_change_detected = true;
      //Serial.println("A long press is detected");
      tft_2_UI_page -= 1;
      if ( tft_2_UI_page < 1) {
        tft_2_UI_page = tft_UI_pages;
      }
    }
  }
  //Serial.println(tft_2_UI_page);
  tft_2_UI_button_lastState = tft_2_UI_button_currentState;


  if (tft_1_change_detected && serial_begun) {
    writeFile(tft_screen_1_file_path, tft_1_UI_page);
    tft_1_bg_drawn = false;
    refresh_screen_1_components();
    tft_1_switch(prev_cpu_temp_val_1, prev_gpu_temp_val_1, prev_cpu_load_val_1, prev_gpu_load_val_1, prev_date_val_1, prev_time_val_1, prev_day_val_1);
    tft_1_change_detected = false;

  }

  if (tft_2_change_detected && serial_begun) {
    writeFile(tft_screen_2_file_path, tft_2_UI_page);
    tft_2_bg_drawn = false;
    refresh_screen_2_components();
    tft_2_switch(prev_cpu_temp_val_2, prev_gpu_temp_val_2, prev_cpu_load_val_2, prev_gpu_load_val_2, prev_date_val_2, prev_time_val_2, prev_day_val_2);
    tft_2_change_detected = false;
  }
}

void poll_buttons_and_switches() {
  poll_exit_switch();
  poll_brightness_divisor_button();
  poll_tft_UI_buttons();
}
