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
      //Expected API: {"message":"on"}
      const char* on_message = jsonDoc["message"];
      if (on_message && strcmp(on_message, "on") == 0) {
        begin_serial();
        serial_begun = true;
      }

      if (serial_begun) {
        //Expected API: {"cpu_temp":"57.6", "gpu_temp":"34.8", "cpu_load":"25.7", "gpu_load":"6.9", "date":"03-11-1994", "time":"11 25 H", "day": "Wednesday"}
        String json_cpu_temp = jsonDoc["cpu_temp"].as<String>();
        String json_gpu_temp = jsonDoc["gpu_temp"].as<String>();
        String json_cpu_load = jsonDoc["cpu_load"].as<String>();
        String json_gpu_load = jsonDoc["gpu_load"].as<String>();
        String json_com_date = jsonDoc["date"].as<String>();
        String json_com_time = jsonDoc["time"].as<String>();
        String json_com_day = jsonDoc["day"].as<String>();
        json_com_day.remove(3);

        tft_1_switch(json_cpu_temp, json_gpu_temp, json_cpu_load, json_gpu_load, json_com_date, json_com_time, json_com_day);
        tft_2_switch(json_cpu_temp, json_gpu_temp, json_cpu_load, json_gpu_load, json_com_date, json_com_time, json_com_day);
        respond_serial();

        prev_date_val_1 = json_com_date;
        prev_day_val_1 = json_com_day;
        prev_time_val_1 = json_com_time;
        prev_date_val_2 = json_com_date;
        prev_day_val_2 = json_com_day;
        prev_time_val_2 = json_com_time;

        prev_cpu_temp_val_1 = json_cpu_temp;
        prev_gpu_temp_val_1 = json_gpu_temp;
        prev_cpu_load_val_1 = json_cpu_load;
        prev_gpu_load_val_1 = json_gpu_load;

        prev_cpu_temp_val_2 = json_cpu_temp;
        prev_gpu_temp_val_2 = json_gpu_temp;
        prev_cpu_load_val_2 = json_cpu_load;
        prev_gpu_load_val_2 = json_gpu_load;
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
  /*
    tft_1.fillScreen(GC9A01A_BLACK);
    tft_2.fillScreen(GC9A01A_BLACK);
    canvasL_1.fillScreen(0);
    canvasR_1.fillScreen(0);
    canvasL_2.fillScreen(0);
    canvasR_2.fillScreen(0);
    canvas_1.fillScreen(0);
    canvas_2.fillScreen(0);
    canvas_3.fillScreen(0);
    tft_1_bg_drawn = false;
    tft_2_bg_drawn = false;
  */
  refresh_all_screen_components();
  serial_begun = true;
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
  serial_begun = false;
  refresh_all_screen_components();
  tft_1_bg_drawn = true;
  tft_2_bg_drawn = true;
}
