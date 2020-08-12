"""
Copyright (C) 2018 SIDDHARTH CHANDRA
Licensed under MIT License

"""

import time
import serial                                      # add Serial library for serial communication
import pyautogui                                   # add pyautogui library for programmatically controlling the mouse and keyboard.

Arduino_Serial = serial.Serial('/dev/ttyACM0',9600)       # Initialize serial and Create Serial port object called Arduino_Serial
 
while 1:
    incoming_data = str(Arduino_Serial.readline()) # read the serial data and print it as line
    print(incoming_data.decode("utf-8"))                            # print the incoming Serial data
    incoming_data = incoming_data.decode("utf-8")
     

    if 'next' in incoming_data:                    # if incoming data is 'next'
        pyautogui.hotkey('ctrl', 'pgdn')           # perform "ctrl+pgdn" operation which moves to the next tab
        time.sleep(1)
        
    if 'down' in incoming_data:                    # if incoming data is 'down'
        pyautogui.scroll(-50) 
        time.sleep(1)

        
    if 'up' in incoming_data:                      # if incoming data is 'up'
        pyautogui.scroll(50)
        time.sleep(1)
        
    incoming_data = ""; 
