void read_serial() {
  /*
    This fucntion waits for the message
    to arrive from python
  */
  if (Serial.available()) {
    String jsonString = Serial.readStringUntil('\n');
    DynamicJsonDocument jsonDoc(256); // Adjust the size if needed
    DeserializationError error = deserializeJson(jsonDoc, jsonString);

    if (error) {
      //Serial.print("JSON parsing error: ");
      //Serial.println(error.c_str());
    } else {
      const char* on_message = jsonDoc["message"];
      if (on_message && strcmp(on_message, "on") == 0) {
        begin_serial();
      }
      respond_serial();

      String cpu_temp = jsonDoc["cpu_temp"].as<String>();
      String gpu_temp = jsonDoc["gpu_temp"].as<String>();
      String com_date = jsonDoc["date"].as<String>();
      String com_time = jsonDoc["time"].as<String>();
      String com_day = jsonDoc["day"].as<String>();

      if (com_date != "0") {

      }
      if (com_time != "0") {

      }
      if (com_day != "0") {

      }

      if (cpu_temp != "0") {
        // Serial.println(cpu_temp);
        int byte_val = 0;
        int int_val = cpu_temp.toInt();
        byte_val = map(int_val, 23, 103, 1, 5);
        show_cpu_temp_val_tft_1(cpu_temp, byte_val);
      }
      if (gpu_temp != "0") {
        // Serial.println(gpu_temp);
        int byte_val = 0;
        int int_val = gpu_temp.toInt();
        byte_val = map(int_val, 23, 103, 1, 5);
        show_gpu_temp_val_tft_2(gpu_temp, byte_val);
      }

    }
  }
}

void begin_serial() {
  /*
    This function sends the response
    in JSON with keys of device
    and message. The value of message
    is a flag on the python side for
    programme control
  */
  StaticJsonDocument<64> jsonDoc;
  jsonDoc["message"] = "hello";
  jsonDoc["device"] = device;
  String jsonString;
  serializeJson(jsonDoc, jsonString);
  Serial.println(jsonString);
  tft_1.fillScreen(GC9A01A_BLACK);
  tft_2.fillScreen(GC9A01A_BLACK);
  delay(1);
}

void respond_serial() {
  /*
    This function sends the response
    in JSON with keys of device
    and message. The value of message
    is a flag on the python side for
    programme control
  */
  StaticJsonDocument<64> jsonDoc;
  jsonDoc["message"] = "done";
  jsonDoc["device"] = device;
  String jsonString;
  serializeJson(jsonDoc, jsonString);
  Serial.println(jsonString);
}

void exit_serial() {
  /*
    This function sends the response
    in JSON with keys of device
    and message. The value of message
    is a flag on the python side for
    programme control
  */
  StaticJsonDocument<64> jsonDoc;
  jsonDoc["message"] = "exit";
  jsonDoc["device"] = device;
  String jsonString;
  serializeJson(jsonDoc, jsonString);
  Serial.println(jsonString);
}
