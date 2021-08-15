#!/usr/bin/env python

import XboxController
import os, sys
import time
import rospy
from std_msgs.msg import String
from head_pkg.msg import Head

headStore = Head()
minin = 1
maxin = 1000
trueBool = 7
falseBool = 3

def callbackHead(data):
    global headStore
    headStore = data

def callBackController(controlId, value):
    #print "Control id = {}, Value = {}".format(controlId, value)
    #for bool 7 is t
    message = headStore
    text = ""
    if controlId == 0: #left stick horizontal (left -1, right 1)
        message.eyesX = translate(value,-1,1,minin,maxin)
    elif controlId == 1: #left stick vertical (up 1, down -1)
        message.eyesY = translate(value,1,-1,minin,maxin)
    elif controlId == 2: #left trigger (out 0, in 1)
        message.eyeSkwint = translate(value,0,1,minin,maxin)
    elif controlId == 3: #right stick horizontal (right -1, left 1)
        message.jawX = translate(value,-1,1,minin,maxin)
    elif controlId == 4: #right stick vertical (up 0, down 1)
        message.jawY = translate(value,1,0,minin,maxin)
    elif controlId == 5: #right trigger (out 0, in 1)
        message.jawZ = translate(value,0,1,minin,maxin)
    elif controlId == 6: #A button
        if value == 1:
            message.expression = 1
        else:
            message.expression = 0
    elif controlId == 7: #B button
        if value == 1:
            message.expression = 2
        else:
            message.expression = 0
    elif controlId == 8: #X button
        if value == 1:
            message.expression = 3
        else:
            message.expression = 0
    elif controlId == 9: #Y button
        if value == 1:
            message.expression = 4
        else:
            message.expression = 0
    elif controlId == 10: #left bumper
        if value == 1:
            message.supprise = trueBool
        else:
            message.supprise = falseBool
    elif controlId == 11: #right bumper
        pass
    elif controlId == 12: #back
        pass
    elif controlId == 13: #start
        pass
    elif controlId == 14: #xbox home
        pass
    elif controlId == 15: #left thumb button
        if value == 1:
            message.blink = trueBool
        else:
            message.blink = falseBool
    elif controlId == 16: #right thumb button
        pass
    elif controlId == 17: #cross pad (horazontal,vertical)
        if value[0] == -1: #left
            text = "hello there"
        elif value[0] == 1: #rigth
            text = "whats up"
        elif value[1] == -1: #down
            text = "how are you"
        elif value[1] == 1: #up
            text = "barnacle boy"
    
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
    return rightMin + (valueScaled * rightSpan)

#def onShutdown():
#    print "xbox controller stopping (callback)"
#    xboxCont.stop()

if __name__ == '__main__':
    print "Starting main script:"
    pubSpeach = rospy.Publisher('speach', String, queue_size=10)
    pubHead = rospy.Publisher('head', Head, queue_size=10)
    rospy.Subscriber('head', Head, callbackHead)
    rospy.init_node('controllInterface', anonymous=True)

    message = headStore
    message.eyesX = 500
    message.eyesY = 500
    message.jawX = 500
    message.jawY = 500
    pubHead.publish(message)

    #rospy.on_shutdown(onShutdown)

    xboxCont = XboxController.XboxController(
        controllerCallBack = callBackController,
        joystickNo = 0,
        deadzone = 0.1,
        scale = 1,
        invertYAxis = False)
        
    #start the controller
    xboxCont.start()
    print "xbox controller running"
    rospy.spin()

    print "xbox controller stopping (spin)"
    xboxCont.stop()