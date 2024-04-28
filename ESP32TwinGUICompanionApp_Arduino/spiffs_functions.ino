void init_spiffs() {
  if (SPIFFS.begin(true)) {
    continue_rw = true;
  } else {
    continue_rw = false;
  }
}

void writeFile(const char* file_path, uint8_t file_data) {
  if (continue_rw) {
    File write_file = SPIFFS.open(file_path, "w");
    if (write_file) {
      write_file.print(file_data);
      write_file.println();
      write_file.close();
    }
  }
}

uint8_t readFile(const char* file_path) {
  if (continue_rw) {
    File read_file = SPIFFS.open(file_path, "r");
    String contents = "";
    if (read_file) {
      while (read_file.available()) {
        contents = read_file.readStringUntil('\n');
        if (read_file.read() == '\n') {
          read_file.close();
          break;
        }
      }
      return contents.toInt();
    } else {
      return 0;
    }
  }
}

void read_spiffs_files_set_params() {
  tft_1_UI_page = readFile(tft_screen_1_file_path);
  tft_2_UI_page = readFile(tft_screen_2_file_path);
  brightness_divisor_array_current_element = readFile(brightness_file_path);
  brightness_divisor = brightness_divisor_array[brightness_divisor_array_current_element];
}
