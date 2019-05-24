import serial, time, glob, os
from datetime import datetime

#ser = serial.Serial('/dev/ttyACM0', 9600) # porta no Arduino
ser = serial.Serial('/dev/ttyS4', 9600) # teste no WSL

while 1:
    serial_line = ser.readline().decode("utf-8")

    print_line = "\"" + datetime.now().isoformat() + "\"," + serial_line

    print(print_line) # If using Python 2.x use: print serial_line
    # Do some other work on the data
    
    with open('serial.csv', 'a') as file:
        file.write(print_line)

    time.sleep(1) # sleep 5 minutes

ser.close() # Only executes once the loop exits

