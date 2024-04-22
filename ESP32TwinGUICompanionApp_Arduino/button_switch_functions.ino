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
  /*
    if (digitalRead(brightness_divisor_button) == HIGH) {
    delay(150); //debounce time
    brightness_divisor_array_current_element += 1;
    if (brightness_divisor_array_current_element >= brightness_divisor_array_size) {
      brightness_divisor_array_current_element = 0;
    }
    writeFile(brightness_file_path, brightness_divisor_array_current_element);
    tft_1_bg_drawn = false;
    tft_2_bg_drawn = false;
    brightness_divisor = brightness_divisor_array[brightness_divisor_array_current_element];
    }*/
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

  if (change_detected) {
    writeFile(brightness_file_path, brightness_divisor_array_current_element);
    tft_1_bg_drawn = false;
    tft_2_bg_drawn = false;
    brightness_divisor = brightness_divisor_array[brightness_divisor_array_current_element];
  }

  brightness_divisor_button_lastState = brightness_divisor_button_currentState;
}

void poll_tft_UI_buttons() {
  bool tft_1_change_detected = false;
  bool tft_2_change_detected = false;

  /*
    if (digitalRead(tft_1_UI_button) == HIGH && serial_begun) {
      delay(150);
      tft_1_UI_page += 1;
      if (tft_1_UI_page > tft_UI_pages) {
        tft_1_UI_page = 1;
      }
      writeFile(tft_screen_1_file_path, tft_1_UI_page);
      refresh_screen_1_components();
    }
  */

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
  if (tft_1_change_detected && serial_begun) {
    writeFile(tft_screen_1_file_path, tft_1_UI_page);
    tft_1_bg_drawn = false;
    refresh_screen_1_components();
  }

  tft_1_UI_button_lastState = tft_1_UI_button_currentState;



  /*
    if (digitalRead(tft_2_UI_button) == HIGH && serial_begun) {
      delay(150);
      tft_2_UI_page += 1;
      if (tft_2_UI_page > tft_UI_pages) {
        tft_2_UI_page = 1;
      }
      writeFile(tft_screen_2_file_path, tft_2_UI_page);
      refresh_screen_2_components();
    }
  */

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
  if (tft_2_change_detected && serial_begun) {
    writeFile(tft_screen_2_file_path, tft_2_UI_page);
    tft_2_bg_drawn = false;
    refresh_screen_2_components();
  }

  tft_2_UI_button_lastState = tft_2_UI_button_currentState;
}

void poll_buttons_and_switches() {
  poll_exit_switch();
  poll_brightness_divisor_button();
  poll_tft_UI_buttons();
}
