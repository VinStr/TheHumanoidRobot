#!/usr/bin/env python

import rospy
import serial
from serial.tools import list_ports
import time
from head_pkg.msg import Head

headStore = Head()
messageFlag = False
trueBool = 7
falseBool = 3

def callbackHead(data):
    global headStore
    headStore = data
    global messageFlag
    messageFlag = True

if __name__ == '__main__':
    rospy.init_node('headInterface', anonymous=True)
    rospy.Subscriber('head', Head, callbackHead)

    for port in list_ports.comports(include_links=False):
        print(str(port) + " : " + str(port.location))
        if port.location == "1-1.2":
            portAdress = str(port.device)
    with serial.Serial(portAdress, 115200, timeout=1) as ser:
        print(ser.name)         # check which port was really used
        time.sleep(2)
        while not rospy.is_shutdown():
            time.sleep(0.01)
            if messageFlag:
                # write commands
                command = ""

                command = command + str(headStore.eyesX).zfill(4)
                command = command + str(headStore.eyesY).zfill(4)

                command = command + str(headStore.jawX).zfill(4)
                command = command + str(headStore.jawY).zfill(4)

                command = command + str(headStore.eyeSkwint).zfill(4)
                command = command + str(headStore.jawZ).zfill(4)

                command = command + str(headStore.expression).zfill(2)

                command = command + str((trueBool-falseBool)*int(headStore.blink)+falseBool)
                command = command + str((trueBool-falseBool)*int(headStore.supprise)+falseBool)

                command = command + str((trueBool-falseBool)*int(headStore.rightNose)+falseBool)
                command = command + str((trueBool-falseBool)*int(headStore.leftNose)+falseBool)

                command = command + '\n'

                #print(command)
                ser.write(command)
                line = ser.readline()
                #print(line)
                if "OK" in line:
                    messageFlag = False
                    
        ser.close()