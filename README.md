![ESP32TwinGUI_to_render front clear](https://github.com/techscapades/ESP32TwinGUI/assets/76870663/1a225e11-2566-4090-a64b-c9b52c310eb4)

This App scan for the ESP32TwinGUI board,
automatically registers it and its serial port
and then sends it the average CPU temp and load,
average GPU temp and load, and the datetime. Information
is sent throught serial at 115200 baud in a JSON object

Currently available for windows only, releases
for other softwares coming out later. I have already
pre-compiled 2 versions of the app, and have left
instructions as to how to compile it yourself too.

I was motivated to make this because I wanted to 
monitor my CPU and GPU temps while gaming without
wanting a second screen to act as the monitor. I 
didn't like the ones that exist in the market because 
the apps weren't open source (could've changed now) 
and I wanted to have full transparency on what this app
is doing, users can also self compile the python 
program into an exe themselves.

The hardware is incredibly capable and I know I'm barely 
scratching the surface of what the GUI can display,
so use LVGL to make it better if you choose. The software
is equally as powerful so I hope that parts of it will
be useful to anyone who needs automatic scanning and
labelling of serial devices as per my other repo.

I have deliberately exposed the I2C pins to allow
for add-ons like an accelerometer to change the 
screen orientation on the fly, alternatively, these pins 
can be used as software serial pins to use the 2 displays 
as a display module in your own projects.

Because it's an ESP32 it can also get information through
WiFi and I've exposed the 5V and GND connections exposed
so users can connect their own batteries to it, just drill a
hole in the bottom housing and solder the power wires, to the 
exposed pads, alternatively, you can just plug in a power bank 
via the usb C port.

This is a fully open source project and anyone is 
welcome to improve and or modify it as they see fit,
stay creative and enjoy!!

![wireframe_front](https://github.com/techscapades/ESP32TwinGUI/assets/76870663/fcc75725-d898-469d-9d13-fc4b4436a89a)
