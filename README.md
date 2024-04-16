This App scan for the ESP32TwinGUI board,
automatically registers it and its serial port
and then sends it the average CPU temp and load,
average GPU temp and load, and the datetime. Information
is sent throught serial at 115200 baud in a JSON object

Currently available for windows only, releases
for other softwares coming out later.

I was motivated to make this because I wanted to 
monitor my CPU and GPU temps while gaming without
wanting a second screen to act as the monitor. The 
hardware is incredibly capable and I know I'm barely 
scratching the surface of what the GUI can display,
so use LVGL to make it better if you choose. The software
is equally as powerful so I hope that parts of it will
be useful to anyone who needs automatic scanning and
labelling of serial devices as per my other repo.

I have deliberately exposed the I2C pins to allow
for add-ons like an accelerometer to change the 
screen orientation etc.. all information is documeted.

This is a fully open source project and anyone is 
welcome to improve and or modify it as they see fit,
stay creative and enjoy!!
