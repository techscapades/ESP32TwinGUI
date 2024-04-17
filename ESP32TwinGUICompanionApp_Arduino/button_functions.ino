void init_buttons() {
  pinMode(exit_serial_button, INPUT_PULLUP);
}

void poll_exit_button() {
  //if this button is pressed, it'll exit the desktop app and reset the board
  if (digitalRead(exit_serial_button) == LOW) {
    unsigned long time_now = millis();
    while (millis() - time_now < 20000) {
      exit_serial();
      delay(10);
    }
  }
}
