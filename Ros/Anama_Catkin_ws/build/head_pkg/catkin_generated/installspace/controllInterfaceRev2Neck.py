#!/usr/bin/env python2

import XboxControllerRev2
import os, sys
import time
import rospy
from std_msgs.msg import String
from head_pkg.msg import Head
from head_pkg.msg import Neck

headStore = Head()
neckStore = Neck()
speachFlag = True
minin = 1
maxin = 1000
HeadMode = True
prevStart = False


def callbackHead(data):
    global headStore
    headStore = data

def callbackNeck(data):
    global neckStore
    neckStore = data

def controllerRead(xboxCont):
    #print "Control id = {}, Value = {}".format(controlId, value)
    #for bool 7 is t
    headMessage = headStore
    neckMessage = neckStore
    text = ""
    
    xboxCont._updateEvent()
    global HeadMode
    global prevStart
    if xboxCont.START and not prevStart:
        HeadMode = not HeadMode
        prevStart = True
        if HeadMode:
            print("Head Mode")
        else:
            print("Neck Mode")
    
    if not xboxCont.START:
        prevStart = False


    #RTHUMBX is RTHUMBY in library
    #RTHUMBY is RTRIGGER in library
    #LTRIGGER is RTHUMBX in library
    #RTRIGGER is LTRIGGER in library
    if HeadMode:

        headMessage.eyesX = translate(xboxCont.LTHUMBX,-1,1,minin,maxin)#left stick horizontal (left -1, right 1)
        
        headMessage.eyesY = translate(xboxCont.LTHUMBY,1,-1,minin,maxin)#left stick vertical (up 1, down -1)

        headMessage.jawX = translate(xboxCont.RTHUMBY,-1,1,minin,maxin)#right stick horizontal (right -1, left 1)

        headMessage.jawY = translate(xboxCont.RTRIGGER,1,0,minin,maxin)#right stick vertical (up 0, down 1)

        headMessage.eyeSkwint = translate(xboxCont.RTHUMBX,0,1,minin,maxin)#left trigger (out 0, in 1)

        headMessage.jawZ = translate(xboxCont.LTRIGGER,0,1,minin,maxin)#right trigger (out 0, in 1)

        if xboxCont.A: #A button
            headMessage.expression = 15
        elif xboxCont.B: #B button
            headMessage.expression = 16
        elif xboxCont.X: #X button
            headMessage.expression = 17
        elif xboxCont.Y: #Y button
            headMessage.expression = 18
        else:
            headMessage.expression = 0
        
        if xboxCont.LB: #left bumper
            headMessage.supprise = True
        else:
            headMessage.supprise = False

        if xboxCont.RB: #right bumper
            headMessage.rightNose = True
            headMessage.leftNose = True
        else:
            headMessage.rightNose = False
            headMessage.leftNose = False

        if xboxCont.LEFTTHUMB: #left thumb button
            headMessage.blink = True
        else:
            headMessage.blink = False

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
        
        pubHead.publish(headMessage)


    else:
        neckMessage.NeckTurnPos = translate(xboxCont.LTHUMBX,-1,1,minin,maxin)#left stick horizontal (left -1, right 1)

        neckMessage.HeadPitch = translate(xboxCont.RTRIGGER,1,0,minin,maxin)#right stick vertical (up 0, down 1)
        
        neckMessage.HeadRoll = translate(xboxCont.RTHUMBY,-1,1,minin,maxin)#right stick horizontal (right -1, left 1)

        pubNeck.publish(neckMessage)
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

    pubNeck = rospy.Publisher('neck', Neck, queue_size=10)
    rospy.Subscriber('neck', Neck, callbackNeck)

    headMessage = headStore
    headMessage.eyesX = 500
    headMessage.eyesY = 500
    headMessage.jawX = 500
    headMessage.jawY = 500
    headMessage.expression = 0
    pubHead.publish(headMessage)

    neckMessage = neckStore
    neckMessage.NeckTurnPos = 500
    neckMessage.HeadPitch = 500
    neckMessage.HeadRoll = 500
    neckMessage.ToungeExpression = 0
    pubNeck.publish(neckMessage)

    xboxCont = XboxControllerRev2.XboxController(
        joystickNo = 0,
        deadzone = 0.1,
        scale = 1,
        invertYAxis = False)
        

    print "xbox controller running Neck"
    while not rospy.is_shutdown():
        time.sleep(0.04)
        controllerRead(xboxCont)