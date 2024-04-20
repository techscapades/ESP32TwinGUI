void init_buttons() {
  pinMode(exit_serial_switch, INPUT_PULLUP);
  pinMode(brightness_divisor_button, INPUT_PULLUP);
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
  if (digitalRead(brightness_divisor_button) == LOW) {
    delay(100); //debounce time
    brightness_divisor_array_current_element += 1;
    if (brightness_divisor_array_current_element >= brightness_divisor_array_size) {
      brightness_divisor_array_current_element = 0;
    }
    brightness_divisor = brightness_divisor_array[brightness_divisor_array_current_element];
  }
}
