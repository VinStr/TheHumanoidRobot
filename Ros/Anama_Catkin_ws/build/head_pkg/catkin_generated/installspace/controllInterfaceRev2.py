#!/usr/bin/env python2

import XboxControllerRev2
import os, sys
import time
import rospy
from std_msgs.msg import String
from head_pkg.msg import Head

headStore = Head()
speachFlag = True
minin = 1
maxin = 1000


def callbackHead(data):
    global headStore
    headStore = data

def controllerRead(xboxCont):
    #print "Control id = {}, Value = {}".format(controlId, value)
    #for bool 7 is t
    message = headStore
    text = ""
    
    xboxCont._updateEvent()

    #RTHUMBX is RTHUMBY in library
    #RTHUMBY is RTRIGGER in library
    #LTRIGGER is RTHUMBX in library
    #RTRIGGER is LTRIGGER in library

    message.eyesX = translate(xboxCont.LTHUMBX,-1,1,minin,maxin)#left stick horizontal (left -1, right 1)
    
    message.eyesY = translate(xboxCont.LTHUMBY,1,-1,minin,maxin)#left stick vertical (up 1, down -1)

    message.jawX = translate(xboxCont.RTHUMBY,-1,1,minin,maxin)#right stick horizontal (right -1, left 1)

    message.jawY = translate(xboxCont.RTRIGGER,1,0,minin,maxin)#right stick vertical (up 0, down 1)

    message.eyeSkwint = translate(xboxCont.RTHUMBX,0,1,minin,maxin)#left trigger (out 0, in 1)

    message.jawZ = translate(xboxCont.LTRIGGER,0,1,minin,maxin)#right trigger (out 0, in 1)

    if xboxCont.A: #A button
        message.expression = 15
    elif xboxCont.B: #B button
        message.expression = 16
    elif xboxCont.X: #X button
        message.expression = 17
    elif xboxCont.Y: #Y button
        message.expression = 18
    else:
        message.expression = 0
    
    if xboxCont.LB: #left bumper
        message.supprise = True
    else:
        message.supprise = False

    if xboxCont.RB: #right bumper
        message.rightNose = True
        message.leftNose = True
    else:
        message.rightNose = False
        message.leftNose = False

    if xboxCont.LEFTTHUMB: #left thumb button
        message.blink = True
    else:
        message.blink = False

    #cross pad (horazontal,vertical)
    global speachFlag
    if xboxCont.DPAD[0] == -1 and speachFlag: #left
        text = "hello there"
        speachFlag = False
    elif xboxCont.DPAD[0] == 1 and speachFlag: #rigth
        text = "whats up"
        speachFlag = False
    elif xboxCont.DPAD[1] == -1 and speachFlag: #down
        text = "how are you"
        speachFlag = False
    elif xboxCont.DPAD[1] == 1 and speachFlag: #up
        text = "barnacle boy"
        speachFlag = False
    elif xboxCont.DPAD[0] == 0 and xboxCont.DPAD[1] == 0:
        speachFlag = True
    
    pubHead.publish(message)
    #print(text)
    if text != "":
        pubSpeach.publish(text)

#translates value from left ---> right
def translate(value, leftMin, leftMax, rightMin, rightMax):
    # Figure out how 'wide' each range is
    leftSpan = leftMax - leftMin
    rightSpan = rightMax - rightMin
    # Convert the left range into a 0-1 range (float)
    valueScaled = float(value - leftMin) / float(leftSpan)
    # Convert the 0-1 range into a value in the right range.
    temp = rightMin + (valueScaled * rightSpan)

    if temp > rightMax:
        temp = rightMax
    elif temp < rightMin:
        temp = rightMin

    return temp

if __name__ == '__main__':
    print "Starting main script:"
    rospy.init_node('controllInterface', anonymous=True)
    
    pubSpeach = rospy.Publisher('speach', String, queue_size=10)
    pubHead = rospy.Publisher('head', Head, queue_size=10)
    rospy.Subscriber('head', Head, callbackHead)
    

    message = headStore
    message.eyesX = 500
    message.eyesY = 500
    message.jawX = 500
    message.jawY = 500
    pubHead.publish(message)

    xboxCont = XboxControllerRev2.XboxController(
        joystickNo = 0,
        deadzone = 0.1,
        scale = 1,
        invertYAxis = False)
        

    print "xbox controller running"
    while not rospy.is_shutdown():
        time.sleep(0.04)
        controllerRead(xboxCont)