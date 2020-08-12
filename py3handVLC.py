"""
Copyright (C) 2018 SIDDHARTH CHANDRA
Licensed under MIT License

"""

import serial #Serial imported for Serial communication
import time #Required to use delay functions
import pyautogui

ArduinoSerial = serial.Serial('/dev/ttyACM0',9600) #Create Serial port object called arduinoSerialData
time.sleep(2) #wait for 2 seconds for the communication to get established

while 1:
    incoming = str (ArduinoSerial.readline()) #read the serial data and print it as line
    incoming = incoming.decode("utf-8")
    print(incoming)
    
    if 'Play/Pause' in incoming:
        pyautogui.typewrite(['space'], 0.2)
        time.sleep(1)

    if 'Rewind' in incoming:
        pyautogui.hotkey('ctrl', 'left')  
        time.sleep(1)
        
    if 'Forward' in incoming:
        pyautogui.hotkey('ctrl', 'right') 
        time.sleep(1)
        
    if 'Vdown' in incoming:
        pyautogui.hotkey('ctrl', 'down')
        time.sleep(1)

    if 'Vup' in incoming:
        pyautogui.hotkey('ctrl', 'up')
        time.sleep(1)
        
    incoming = "";
