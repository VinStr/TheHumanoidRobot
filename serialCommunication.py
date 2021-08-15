import serial
from serial.tools import list_ports


for port in list_ports.comports(include_links=True):
    print(str(port) + " : " + str(port.location))
    if port.location == "1-1.3":
       portAdress = str(port.device)

#ser = serial.Serial(portAdress)  # open serial port
#print(ser.name)         # check which port was really used
#ser.write(b'hello')     # write a string
#ser.close()             # close port