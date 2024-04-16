'''
This program scans for the ESP32TwinGUI board,
automatically registers it and its serial port
and then sends it the average CPU temp and load,
average GPU temp and load, and the datetime
@techscapades 2023 https://github.com/techscapades
'''
import usb.core
import usb.util
import usb.backend.libusb1
import json
import serial
import serial.tools.list_ports
import time
import clr  # the pythonnet module.
from pathlib import Path
import atexit
import os
import tkinter as tk
from PIL import Image, ImageTk, ImageDraw, ImageFont
import pyuac
import threading
import datetime

if not pyuac.isUserAdmin():
    pyuac.runAsAdmin()

OHM_path_root = Path.cwd()
OHM_path_root = str(OHM_path_root) + r'\OpenHardwareMonitorLib'
print(OHM_path_root)

pyfilename = os.path.splitext(os.path.basename(__file__))[0]
pyfilename = pyfilename + '.exe'
print(pyfilename)

clr.AddReference(OHM_path_root)


def start_screen():
    # Create a Tkinter window
    root = tk.Tk()
    root.overrideredirect(True)  # Remove window decorations

    # Load the image
    image = Image.open("splash_screen_image.png")  # Replace "splash_screen.png" with your image file
    image = image.resize((400, 400))

    draw = ImageDraw.Draw(image)
    font = ImageFont.truetype("arial.ttf", 20)  # Change the font and size as needed
    text = "Initialising..."  # Your text here
    draw.text((150, 370), text, fill="black", font=font)
    text1 = "ESP32TwinGUI"  # Your text here
    draw.text((3, 0), text1, fill="black", font=font)
    text2 = "DoctorQDesigns"  # Your text here
    draw.text((252, 0), text2, fill="black", font=font)

    photo = ImageTk.PhotoImage(image)

    # Display the image on the window
    label = tk.Label(root, image=photo)
    label.pack()

    # Center the window on the screen
    root.update_idletasks()
    width = root.winfo_width()
    height = root.winfo_height()
    x = (root.winfo_screenwidth() // 2) - (width // 2)
    y = (root.winfo_screenheight() // 2) - (height // 2)
    root.geometry(f"{width}x{height}+{x}+{y}")

    # Close the window after a certain duration
    root.after(3000, root.destroy)  # Change 3000 to the duration in milliseconds

    root.mainloop()


def end_screen():
    # Create a Tkinter window
    root = tk.Tk()
    root.overrideredirect(True)  # Remove window decorations

    # Load the image
    image = Image.open("splash_screen_image.png")  # Replace "splash_screen.png" with your image file
    image = image.resize((400, 400))

    draw = ImageDraw.Draw(image)
    font = ImageFont.truetype("arial.ttf", 20)  # Change the font and size as needed
    text = "Exiting..."  # Your text here
    draw.text((165, 370), text, fill="black", font=font)
    text1 = "ESP32TwinGUI"  # Your text here
    draw.text((3, 0), text1, fill="black", font=font)
    text2 = "DoctorQDesigns"  # Your text here
    draw.text((252, 0), text2, fill="black", font=font)

    photo = ImageTk.PhotoImage(image)

    # Display the image on the window
    label = tk.Label(root, image=photo)
    label.pack()

    # Center the window on the screen
    root.update_idletasks()
    width = root.winfo_width()
    height = root.winfo_height()
    x = (root.winfo_screenwidth() // 2) - (width // 2)
    y = (root.winfo_screenheight() // 2) - (height // 2)
    root.geometry(f"{width}x{height}+{x}+{y}")

    # Close the window after a certain duration
    root.after(3000, root.destroy)  # Change 3000 to the duration in milliseconds

    root.mainloop()


def exit_function():
    print("Closing GPU and CPU temp program, releasing ESP32TwinGUI")
    end_screen()
    exit_string = 'wmic process where name="' + pyfilename + '" delete'
    print(exit_string)
    time.sleep(2)
    os.system(exit_string)


atexit.register(exit_function)

thread = threading.Thread(target=start_screen)
thread.start()

baud_rate = 115200  # default baud rate
device_id_list = ["303a:1001"]  # list of device_ids to scan for, use 'lsusb' command on terminal
device_dictionary = {}
windows_check = [False]

if os.name == 'nt':
    path_root = Path.cwd()
    path_root = str(path_root) + r"\libusb-1.0.dll"
    print(path_root)
    backend = usb.backend.libusb1.get_backend(find_library=lambda x: path_root)  # adapt to your path
    windows_check[0] = True


def get_usb_device_metadata(device):
    # Function to get USB device metadata
    metadata = {
        "device_id": f"{device.idVendor:04x}:{device.idProduct:04x}"
    }
    return metadata


def detect_usb_devices(device_id_list):
    # Function to detect and list USB devices with device_id in device_id_list
    if windows_check[0]:
        devices = usb.core.find(backend=backend, find_all=True)
    else:
        devices = usb.core.find(find_all=True)
    usb_device_list = []

    for device in devices:
        device_metadata = get_usb_device_metadata(device)
        if device_metadata["device_id"] in device_id_list:
            usb_device_list.append(device_metadata)
    return usb_device_list


def list_serial_ports():
    # function to detect all serial ports
    ports_list = []
    ports = serial.tools.list_ports.comports()
    serial_ports = [port.device for port in ports]
    for available_port in serial_ports:
        # append to list only if its /ttyUSB*
        if 'USB' in available_port:
            ports_list.append(available_port)
    return serial_ports


def generate_serial_objects(get_device_ports):
    device_serial_list = []
    for i in range(len(get_device_ports)):
        try:
            device_serial_list.append(
                serial.Serial(get_device_ports[i], baud_rate, timeout=2, write_timeout=2))
        except:
            print(f'Error opening {get_device_ports[i]}')
    return device_serial_list


device_ports = list_serial_ports()  # get a list of all serial ports
# get a list of all relevant usb devices
usb_devices = detect_usb_devices(device_id_list)
serial_objects = generate_serial_objects(device_ports)  # get a list of all serial objects

print(device_ports)
print(usb_devices)
print(serial_objects)
print(type(serial_objects))

print('========= Scanning for ESP32TwinGUI now =========')
time.sleep(1)
i = 0  # iterator for device_ports list
try_times = 2
unknown_devices = 0
for serial_object in serial_objects:
    while True:  # keep sending the message on the same serial port until response is received
        if type(serial_object) is None:
            serial_objects.remove(serial_object)
            break
        else:
            try:
                data = json.dumps({"message": "on"})  # send some JSON data
                serial_object.write(data.encode('utf-8'))
                time.sleep(0.01)  # short interval to pause serial activity
                received_data = serial_object.readline().decode('utf-8')  # recieve data
                try:
                    json_data = json.loads(received_data)
                    print("Received JSON data:")
                    print(json_data)
                    if json_data['message'] == 'hello' and json_data['device'] == 'ESP32TwinGUI':
                        print(json_data['device'])
                        device_dictionary[json_data['device']] = {'path': device_ports[i],
                                                                  'serial_info': serial_object}
                        i = i + 1
                        break  # message is successflly recieved
                    else:
                        i = i + 1
                    if i > try_times:
                        break
                except json.JSONDecodeError as e:
                    print(f"Error decoding JSON data: {e}")  # might happen
                except:
                    print("unkown device detected")
                    unknown_devices = unknown_devices + 1
                    device_dictionary['unknown_devices'] = unknown_devices
                    i = i + 1
                    break
                i = i + 1
                if i > try_times:
                    break
            except:
                print(f'write timeout of {serial_object}')
                i = i + 1
            if i > try_times:
                break

# include this for double checking device types
device_dictionary['usb_devices'] = usb_devices
print('========= Finished Scanning for ESP32TwinGUI =========')

print('Device dictionary')
print(device_dictionary)

print('========= Getting CPU and GPU data, starting communication with ESP32TwinGui =========')
from OpenHardwareMonitor.Hardware import Computer

c = Computer()
c.CPUEnabled = True  # get the Info about CPU
c.GPUEnabled = True  # get the Info about GPU
c.Open()

av_gpu_temp = [0]
av_cpu_temp = [0]
av_gpu_load = [0]
av_cpu_load = [0]
data_dict = {'cpu_temp': av_cpu_temp[0], 'gpu_temp': av_gpu_temp[0],
             'cpu_load': av_cpu_load[0], 'gpu_load': av_gpu_load[0]}
exit_handler = [False]
com_day = "0"
com_time = "0"
com_date = "0"

while True:
    """
    try block to get date and time
    """
    try:
        dt_now = datetime.datetime.now()
        com_date = str(dt_now.strftime("%d-%m-%y"))
        com_time = str(dt_now.strftime("%H %M H"))
        com_day = str(dt_now.strftime("%A"))
    except:
        error = 0
        com_day = "-1"
        com_time = "-1"
        com_date = "-1"

    """
    try block to get CPU temps
    """
    try:
        cpu_temp = 0
        num_cpu_probes = 0
        for a in range(0, len(c.Hardware[0].Sensors)):
            # print(c.Hardware[0].Sensors[a].Identifier)
            # '''
            if "/temperature" in str(c.Hardware[0].Sensors[a].Identifier):
                # print(c.Hardware[0].Sensors[a].get_Value())
                if c.Hardware[0].Sensors[a].get_Value() is not None:
                    cpu_temp = c.Hardware[0].Sensors[a].get_Value() + cpu_temp
                    num_cpu_probes = num_cpu_probes + 1
            # '''
        try:
            average_cpu_temp = cpu_temp / num_cpu_probes
            print(f"CPU Temp: {round(average_cpu_temp, 1)}")
            av_cpu_temp[0] = str(round(average_cpu_temp, 1))
        except ZeroDivisionError:
            error = 1
    except:
        error = 2

    """
    try block to get CPU loads
    """
    try:
        cpu_load = 0
        num_cpu_probes = 0
        for a in range(0, len(c.Hardware[0].Sensors)):
            # print(c.Hardware[0].Sensors[a].Identifier)
            # '''
            if "/load" in str(c.Hardware[0].Sensors[a].Identifier):
                # print(c.Hardware[0].Sensors[a].get_Value())
                if c.Hardware[0].Sensors[a].get_Value() is not None:
                    cpu_load = c.Hardware[0].Sensors[a].get_Value() + cpu_load
                    num_cpu_probes = num_cpu_probes + 1
            # '''
        try:
            average_cpu_load = cpu_load / num_cpu_probes
            print(f"CPU Load: {round(average_cpu_load, 1)}")
            av_cpu_load[0] = str(round(average_cpu_load, 1))
        except ZeroDivisionError:
            error = 3
    except:
        error = 4

    """
    try block to get GPU temps
    """
    try:
        gpu_temp = 0
        num_gpu_probes = 0
        for a in range(0, len(c.Hardware[1].Sensors)):
            # print(c.Hardware[1].Sensors[a].Identifier)
            # '''
            if "/temperature" in str(c.Hardware[1].Sensors[a].Identifier):
                # print(c.Hardware[1].Sensors[a].get_Value())
                if c.Hardware[1].Sensors[a].get_Value() is not None:
                    gpu_temp = c.Hardware[1].Sensors[a].get_Value() + gpu_temp
                    num_gpu_probes = num_gpu_probes + 1
            # '''
        try:
            average_gpu_temp = gpu_temp / num_gpu_probes
            print(f"GPU Temp: {round(average_gpu_temp, 1)}")
            av_gpu_temp[0] = str(round(average_gpu_temp, 1))
        except ZeroDivisionError:
            error = 5
    except:
        error = 6

    """
    try block to get GPU loads
    """
    try:
        gpu_load = 0
        num_gpu_probes = 0
        for a in range(0, len(c.Hardware[1].Sensors)):
            # print(c.Hardware[0].Sensors[a].Identifier)
            # '''
            if "/load" in str(c.Hardware[1].Sensors[a].Identifier):
                # print(c.Hardware[0].Sensors[a].get_Value())
                if c.Hardware[1].Sensors[a].get_Value() is not None:
                    gpu_load = c.Hardware[1].Sensors[a].get_Value() + gpu_load
                    num_gpu_probes = num_gpu_probes + 1
            # '''
        try:
            average_gpu_load = gpu_load / num_gpu_probes
            print(f"GPU Load: {round(average_gpu_load, 1)}")
            av_gpu_load[0] = str(round(average_gpu_load, 1))
        except ZeroDivisionError:
            error = 7
    except:
        error = 8

    """
    block to write to serial device
    """

    data = json.dumps({'cpu_temp': av_cpu_temp[0], 'gpu_temp': av_gpu_temp[0],
                       'cpu_load': av_cpu_load[0], 'gpu_load': av_gpu_load[0],
                       'date': com_date, 'time': com_time, 'day': com_day})
    # data = json.dumps({"cpu_temp": "29.1", "gpu_temp": "55.8"})
    retry = 5
    outer_retries = 0
    while True:
        outer_retries = outer_retries + 1
        try:
            serial_object = device_dictionary['ESP32TwinGUI']['serial_info']
            serial_object.write(data.encode('utf-8'))
            received_data = serial_object.readline().decode('utf-8')  # recieve data
            json_data = json.loads(received_data)
            print("Received JSON data:")
            print(json_data)
            if json_data['message'] == 'done':
                break
            if json_data['message'] == 'exit':
                exit_handler[0] = True
                break
        except:
            print('Exception occurred: device not found!')
            serial_object.close()
            device_ports = list_serial_ports()  # get a list of all serial ports
            # get a list of all relevant usb devices
            usb_devices = detect_usb_devices(device_id_list)
            serial_objects = generate_serial_objects(
                device_ports)  # get a list of all serial objects
            i = 0  # iterator for device_ports list
            j = 0
            unknown_devices = 0
            for serial_object in serial_objects:
                while True:  # keep sending the message on the same serial port until response is received
                    print('Trying to reconnect!')
                    time.sleep(1)
                    if type(serial_object) is None:
                        serial_objects.remove(serial_object)
                        break
                    else:
                        try:
                            data = json.dumps({"message": "on"})  # send some JSON data
                            serial_object.write(data.encode('utf-8'))
                            time.sleep(0.01)  # short interval to pause serial activity
                            received_data = serial_object.readline().decode('utf-8')  # recieve data
                            try:
                                json_data = json.loads(received_data)
                                print("Received JSON data:")
                                print(json_data)
                                if json_data['message'] == 'hello' and json_data['device'] == 'ESP32TwinGUI':
                                    print(json_data['device'])
                                    device_dictionary[json_data['device']] = {'path': device_ports[i],
                                                                              'serial_info': serial_object}
                                    i = i + 1
                                    break  # message is successflly recieved
                                else:
                                    i = i + 1
                                if i > retry:
                                    break
                                if json_data['message'] == 'exit':
                                    exit()
                            except json.JSONDecodeError as e:
                                print(f"Error decoding JSON data: {e}")  # might happen
                                i = i + 1
                                if i > retry:
                                    break
                                else:
                                    continue
                            except:
                                print("unknown device detected")
                                unknown_devices = unknown_devices + 1
                                device_dictionary['unknown_devices'] = unknown_devices
                                j = j + 1
                                break
                        except:
                            print(f'write timeout of {serial_object}')
                            i = i + 1
                        if i > retry:
                            break

        if outer_retries > retry:
            print("Reached max number of attempts to reconnect, exiting program")
            exit()
        else:
            time.sleep(3)

    if exit_handler[0]:
        break

    c.Hardware[0].Update()
    c.Hardware[1].Update()
    time.sleep(3)
