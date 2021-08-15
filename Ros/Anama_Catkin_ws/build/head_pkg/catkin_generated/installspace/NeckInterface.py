#!/usr/bin/env python2

import rospy
import serial
from serial.tools import list_ports
import time
from head_pkg.msg import Neck

neckStore = Neck()
messageFlag = False
trueBool = 7
falseBool = 3

def callbackNeck(data):
    global neckStore
    global messageFlag

    #if(neckStore.NeckTurnPos!=data.NeckTurnPos or neckStore.HeadPitch!=data.HeadPitch or neckStore.HeadRoll!=data.HeadRoll or neckStore.ToungeExpression!=data.ToungeExpression):
    if(neckStore != data):
        neckStore = data
        messageFlag = True
    

if __name__ == '__main__':
    rospy.init_node('neckInterface', anonymous=True)
    rospy.Subscriber('neck', Neck, callbackNeck)
    pubNeck = rospy.Publisher('neck', Neck, queue_size=10)

    for port in list_ports.comports(include_links=False):
        print(str(port) + " : " + str(port.location))
        if port.location == "1-1.1":
            portAdress = str(port.device)
    with serial.Serial(portAdress, 115200, timeout=1) as ser:
        print("using port: " + ser.name)         # check which port was really used
        time.sleep(2)
        while not rospy.is_shutdown():
            time.sleep(0.01)
            if messageFlag:
                # write commands
                command = ""

                command = command + str(neckStore.NeckTurnPos).zfill(4)

                command = command + str(neckStore.HeadPitch).zfill(4)
                command = command + str(neckStore.HeadRoll).zfill(4)

                command = command + str(neckStore.ToungeExpression).zfill(2)

                command = command + '\n'

                #print(command)
                ser.write(command)
                line = ser.readline()
                #print(line)

                global neckStore
                tmp = line[line.index('~')+1:line.index(',')]
                #print(tmp)
                neckStore.SensPitch = float(tmp)
                tmp = line.replace(line[:line.index(',')],"")
                tmp = tmp[1:tmp.index('~')]
                #print(tmp)
                neckStore.SensRoll = float(tmp)
                pubNeck.publish(neckStore)
                
                if "OK" in line:
                    messageFlag = False
                    
        ser.close()