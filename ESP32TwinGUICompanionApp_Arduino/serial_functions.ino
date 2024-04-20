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
        String cpu_temp = jsonDoc["cpu_temp"].as<String>();
        String gpu_temp = jsonDoc["gpu_temp"].as<String>();
        String cpu_load = jsonDoc["cpu_load"].as<String>();
        String gpu_load = jsonDoc["gpu_load"].as<String>();
        String com_date = jsonDoc["date"].as<String>();
        String com_time = jsonDoc["time"].as<String>();
        String com_day = jsonDoc["day"].as<String>();

        if (com_date != "0") {

        }
        if (com_time != "0") {

        }
        if (com_day != "0") {

        }

        if (cpu_temp != "0" && cpu_load != "0") {
          if (cpu_temp.length() == 3) {
            cpu_temp = "0" + cpu_temp;
          }
          if (cpu_temp.length() == 5) {
            cpu_temp.remove(3, 2);
          }
          if (cpu_load.length() == 3) {
            cpu_load = "0" + cpu_load;
          }
          if (cpu_load.length() == 5) {
            cpu_load.remove(3, 2);
          }
          // Serial.println(cpu_temp);
          // Serial.println(cpu_load);
          if (prev_cpu_temp_val != cpu_temp || prev_cpu_load_val != cpu_load) {
            int byte_val_cpu_temp = 0;
            int int_val_cpu_temp = cpu_temp.toInt();
            int byte_val_cpu_load = 0;
            int int_val_cpu_load = cpu_load.toInt();

            byte_val_cpu_temp = map(int_val_cpu_temp, 23, 103, 1, 5);
            byte_val_cpu_load = map(int_val_cpu_load, 23, 103, 1, 5);
            show_cpu_temp_and_load_val_tft_1(cpu_temp, cpu_load, byte_val_cpu_temp, byte_val_cpu_load);
          }
        }

        /*
                if (cpu_temp != "0" && cpu_load != "0") {
                  if (cpu_temp.length() == 3) {
                    cpu_temp = "0" + cpu_temp;
                  }
                  if (cpu_temp.length() == 5) {
                    cpu_temp.remove(3, 2);
                  }
                  if (cpu_load.length() == 3) {
                    cpu_load = "0" + cpu_load;
                  }
                  if (cpu_load.length() == 5) {
                    cpu_load.remove(3, 2);
                  }
                  // Serial.println(cpu_temp);
                  // Serial.println(cpu_load);
                  if (prev_cpu_temp_val != cpu_temp || prev_cpu_load_val != cpu_load) {
                    int byte_val_cpu_temp = 0;
                    int int_val_cpu_temp = cpu_temp.toInt();
                    int byte_val_cpu_load = 0;
                    int int_val_cpu_load = cpu_load.toInt();

                    byte_val_cpu_temp = map(int_val_cpu_temp, 23, 103, 1, 5);
                    byte_val_cpu_load = map(int_val_cpu_load, 23, 103, 1, 5);
                    show_cpu_temp_and_load_val_tft_2(cpu_temp, cpu_load, byte_val_cpu_temp, byte_val_cpu_load);
                  }
                }
        */
        /*
                if (gpu_temp != "0" && gpu_load != "0") {
                  if (gpu_temp.length() == 3) {
                    gpu_temp = "0" + gpu_temp;
                  }
                  if (gpu_temp.length() == 5) {
                    gpu_temp.remove(4, 2);
                  }
                  if (gpu_load.length() == 3) {
                    gpu_load = "0" + gpu_load;
                  }
                  if (gpu_load.length() == 5) {
                    gpu_load.remove(4, 2);
                  }
                  // Serial.println(gpu_temp);
                  // Serial.println(gpu_load);
                  if (prev_gpu_temp_val != gpu_temp || prev_gpu_load_val != gpu_load) {
                    int byte_val_gpu_temp = 0;
                    int int_val_gpu_temp = gpu_temp.toInt();
                    int byte_val_gpu_load = 0;
                    int int_val_gpu_load = gpu_load.toInt();

                    byte_val_gpu_temp = map(int_val_gpu_temp, 23, 103, 1, 5);
                    byte_val_gpu_load = map(int_val_gpu_load, 23, 103, 1, 5);
                    show_gpu_temp_and_load_val_tft_1(gpu_temp, gpu_load, byte_val_gpu_temp, byte_val_gpu_load);
                  }
                }
        */

        if (gpu_temp != "0" && gpu_load != "0") {
          if (gpu_temp.length() == 3) {
            gpu_temp = "0" + gpu_temp;
          }
          if (gpu_temp.length() == 5) {
            gpu_temp.remove(4, 2);
          }
          if (gpu_load.length() == 3) {
            gpu_load = "0" + gpu_load;
          }
          if (gpu_load.length() == 5) {
            gpu_load.remove(4, 2);
          }
          // Serial.println(gpu_temp);
          // Serial.println(gpu_load);
          if (prev_gpu_temp_val != gpu_temp || prev_gpu_load_val != gpu_load) {
            int byte_val_gpu_temp = 0;
            int int_val_gpu_temp = gpu_temp.toInt();
            int byte_val_gpu_load = 0;
            int int_val_gpu_load = gpu_load.toInt();

            byte_val_gpu_temp = map(int_val_gpu_temp, 23, 103, 1, 5);
            byte_val_gpu_load = map(int_val_gpu_load, 23, 103, 1, 5);
            show_gpu_temp_and_load_val_tft_2(gpu_temp, gpu_load, byte_val_gpu_temp, byte_val_gpu_load);
          }
        }


        /*

                if (cpu_temp != "0") {
                  if (cpu_temp.length() == 3) {
                    cpu_temp = "0" + cpu_temp;
                  }
                  if (cpu_temp.length() == 5) {
                    cpu_temp.remove(3, 2);
                  }
                  // Serial.println(cpu_temp);
                  if (prev_cpu_temp_val != cpu_temp) {
                    int byte_val = 0;
                    int int_val = cpu_temp.toInt();
                    byte_val = map(int_val, 23, 103, 1, 5);
                    show_cpu_temp_val_tft_1(cpu_temp, byte_val);
                  }
                }
                if (gpu_temp != "0") {
                  if (gpu_temp.length() == 3) {
                    gpu_temp = "0" + gpu_temp;
                  }
                  if (gpu_temp.length() == 5) {
                    gpu_temp.remove(3, 2);
                  }
                  // Serial.println(gpu_temp);
                  if (prev_gpu_temp_val != gpu_temp) {
                    int byte_val = 0;
                    int int_val = gpu_temp.toInt();
                    byte_val = map(int_val, 23, 103, 1, 5);
                    show_gpu_temp_val_tft_2(gpu_temp, byte_val);
                  }
                }



                if (cpu_load != "0") {
                  if (cpu_load.length() == 3) {
                    cpu_load = "0" + cpu_load;
                  }
                  if (cpu_load.length() == 5) {
                    cpu_load.remove(3, 2);
                  }
                  // Serial.println(cpu_load);
                  if (prev_cpu_load_val != cpu_load) {
                    int byte_val = 0;
                    int int_val = cpu_load.toInt();
                    byte_val = map(int_val, 23, 103, 1, 5);
                    show_cpu_load_val_tft_1(cpu_load, byte_val);
                  }
                }

                if (gpu_load != "0") {
                  if (gpu_load.length() == 3) {
                    gpu_load = "0" + gpu_load;
                  }
                  if (gpu_load.length() == 5) {
                    gpu_load.remove(3, 2);
                  }
                  // Serial.println(gpu_load);
                  if (prev_gpu_load_val != gpu_load) {
                    int byte_val = 0;
                    int int_val = gpu_load.toInt();
                    byte_val = map(int_val, 23, 103, 1, 5);
                    show_gpu_load_val_tft_2(gpu_load, byte_val);
                  }
                }
        */


        respond_serial();
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
  canvasL_1.fillScreen(0);
  canvasR_1.fillScreen(0);
  canvasL_2.fillScreen(0);
  canvasR_2.fillScreen(0);
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
}
