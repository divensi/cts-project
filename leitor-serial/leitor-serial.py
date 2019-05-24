import serial, time, glob, os

ser = serial.Serial('/dev/ttyACM0', 9600) # porta no Arduino
#ser = serial.Serial('/dev/ttyS4', 9600) # teste no WSL

while 1:
    serial_line = ser.readline()

    print(serial_line.decode("utf-8")) # If using Python 2.x use: print serial_line
    # Do some other work on the data
    
    #try:
    with open('serial.csv', 'a') as file:
        file.write(serial_line.decode("utf-8"))

    #except:
    #print('Nao foi possivel abrir o arquivo para escrita')


    time.sleep(1) # sleep 5 minutes

    # Loop restarts once the sleep is finished

ser.close() # Only executes once the loop exits

