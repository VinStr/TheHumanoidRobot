#!/usr/bin/env python

import serial
from serial.tools import list_ports
import time

messageFlag = False


if __name__ == '__main__':

    for port in list_ports.comports(include_links=False):
        print(str(port) + " : " + str(port.location))
        if port.location == "1-1.3":
            portAdress = str(port.device)
    with serial.Serial(portAdress, 115200, timeout=1) as ser:
        print(ser.name)         # check which port was really used
        time.sleep(3)
        while True:
            txt = raw_input("say somthing: ")
            eye = int(txt)
            messageFlag = True
            while messageFlag:
                # write commands
                command = ""

                command = command + str(500).zfill(4)
                command = command + str(500).zfill(4)

                command = command + str(500).zfill(4)
                command = command + str(500).zfill(4)

                command = command + str(500).zfill(4)
                command = command + str(500).zfill(4)

                command = command + str(eye).zfill(2)

                command = command + str(0)
                command = command + str(0)

                command = command + str(0)
                command = command + str(0)

                command = command + str(0)
                command = command + str(0)
                command = command + str(0)
                command = command + str(0)

                command = command + str(0)
                command = command + str(0)
                command = command + str(0)

                command = command + '\n'

                print(command)
                ser.write(command)

                line = ser.readline()
                print(line)
                if "OK" in line:
                    messageFlag = False
                    print("sent")