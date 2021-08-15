#!/usr/bin/env python

import rospy
import serial
from serial.tools import list_ports
import time
from inject_pkg.msg import InjectorMsg
import automationhat

maxPos = 10000 #ticks
maxDist = 1500 #mm
targetRange = 10

currentPos = 0
targetPos = 0
direction = 0

def callback(data):
    global targetPos
    targetPos = translate(data.targetPos,0,maxDist,0,maxPos)
    #print("new value: " + str(targetPos))

def translate(value, leftMin, leftMax, rightMin, rightMax):
    # Figure out how 'wide' each range is
    leftSpan = leftMax - leftMin
    rightSpan = rightMax - rightMin
    # Convert the left range into a 0-1 range (float)
    valueScaled = float(value - leftMin) / float(leftSpan)
    # Convert the 0-1 range into a value in the right range.
    return rightMin + (valueScaled * rightSpan)

if __name__ == '__main__':
    #https://playground.arduino.cc/Main/DisablingAutoResetOnSerialConnection/
    rospy.init_node('injectorControl', anonymous=True)
    rospy.Subscriber('injection', InjectorMsg, callback)
    pub = rospy.Publisher('injection', InjectorMsg, queue_size=10)
    rate = rospy.Rate(10) # 10hz

    for port in list_ports.comports(include_links=False):
        print(str(port) + " : " + str(port.location))
        if port.location == "1-1.1":
            portAdress = str(port.device)
    with serial.Serial(portAdress, 115200, timeout=1) as ser:
        print(ser.name)         # check which port was really used
        while not rospy.is_shutdown():
            rate.sleep()
            time.sleep(0.1)
            #------------------get positions
            ser.write(b'P \n')     # write a string
            line = ser.readline() 
            currentPos = int(line[1:])
            #print(str(currentPos)+":"+str(targetPos))
            #ser.close()             # close port

            message = InjectorMsg()
            message.currentPos = translate(currentPos,0,maxPos,0,maxDist)
            message.targetPos = translate(targetPos,0,maxPos,0,maxDist)
            #------------------set direction from pos
            if(currentPos > (targetPos + targetRange)):
                direction = 1
            elif (currentPos < (targetPos - targetRange)):
                direction = -1
            else:
                direction = 0

            #------------------check limit switches
            if automationhat.is_automation_hat():
                if (automationhat.input.one.read() and direction == 1):
                    direction = 0
                elif (automationhat.input.two.read() and direction == -1):
                    direction = 0
                message.limit1 = automationhat.input.one.read()
                message.limit2 = automationhat.input.two.read()

            #------------------move relays to position
            if automationhat.is_automation_hat():
                if(direction == 1):
                    automationhat.relay.one.write(0)
                    automationhat.relay.two.write(1)
                elif(direction == -1):
                    automationhat.relay.two.write(0)
                    automationhat.relay.one.write(1)
                else:
                    automationhat.relay.two.write(0)
                    automationhat.relay.one.write(0)
            
            pub.publish(message)

