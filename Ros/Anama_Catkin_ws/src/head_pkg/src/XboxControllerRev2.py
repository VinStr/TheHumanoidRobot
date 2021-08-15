#Martin O'Hanlon
#www.stuffaboutcode.com
#A class for reading values from an xbox controller
# uses xboxdrv and pygame
# xboxdrv should already be running
# https://www.stuffaboutcode.com/2014/10/raspberry-pi-xbox-360-controller-python.html

import pygame
from pygame.locals import *
import os, sys
import threading
import time

"""
NOTES - pygame events and values

JOYAXISMOTION
event.axis              event.value
0 - x axis left thumb   (+1 is right, -1 is left)
1 - y axis left thumb   (+1 is down, -1 is up)
2 - x axis right thumb  (+1 is right, -1 is left)
3 - y axis right thumb  (+1 is down, -1 is up)
4 - right trigger
5 - left trigger

JOYBUTTONDOWN | JOYBUTTONUP
event.button
A = 0
B = 1
X = 2
Y = 3
LB = 4
RB = 5
BACK = 6
START = 7
XBOX = 8
LEFTTHUMB = 9
RIGHTTHUMB = 10

JOYHATMOTION
event.value
[0] - horizontal
[1] - vertival
[0].0 - middle
[0].-1 - left
[0].+1 - right
[1].0 - middle
[1].-1 - bottom
[1].+1 - top

"""
#Main class for reading the xbox controller values
class XboxController(threading.Thread):

    #internal ids for the xbox controls
    class XboxControls():
        LTHUMBX = 0
        LTHUMBY = 1
        RTHUMBX = 2
        RTHUMBY = 3
        RTRIGGER = 4
        LTRIGGER = 5
        A = 6
        B = 7
        X = 8
        Y = 9
        LB = 10
        RB = 11
        BACK = 12
        START = 13
        XBOX = 14
        LEFTTHUMB = 15
        RIGHTTHUMB = 16
        DPAD = 17

    #pygame axis constants for the analogue controls of the xbox controller
    class PyGameAxis():
        LTHUMBX = 0
        LTHUMBY = 1
        RTHUMBX = 2
        RTHUMBY = 3
        RTRIGGER = 4
        LTRIGGER = 5

    #pygame constants for the buttons of the xbox controller
    class PyGameButtons():
        A = 0
        B = 1
        X = 2
        Y = 3
        LB = 4
        RB = 5
        BACK = 6
        START = 7
        XBOX = 8
        LEFTTHUMB = 9
        RIGHTTHUMB = 10

    #map between pygame axis (analogue stick) ids and xbox control ids
    AXISCONTROLMAP = {PyGameAxis.LTHUMBX: XboxControls.LTHUMBX,
                      PyGameAxis.LTHUMBY: XboxControls.LTHUMBY,
                      PyGameAxis.RTHUMBX: XboxControls.RTHUMBX,
                      PyGameAxis.RTHUMBY: XboxControls.RTHUMBY}
    
    #map between pygame axis (trigger) ids and xbox control ids
    TRIGGERCONTROLMAP = {PyGameAxis.RTRIGGER: XboxControls.RTRIGGER,
                         PyGameAxis.LTRIGGER: XboxControls.LTRIGGER}

    #map between pygame buttons ids and xbox contorl ids
    BUTTONCONTROLMAP = {PyGameButtons.A: XboxControls.A,
                        PyGameButtons.B: XboxControls.B,
                        PyGameButtons.X: XboxControls.X,
                        PyGameButtons.Y: XboxControls.Y,
                        PyGameButtons.LB: XboxControls.LB,
                        PyGameButtons.RB: XboxControls.RB,
                        PyGameButtons.BACK: XboxControls.BACK,
                        PyGameButtons.START: XboxControls.START,
                        PyGameButtons.XBOX: XboxControls.XBOX,
                        PyGameButtons.LEFTTHUMB: XboxControls.LEFTTHUMB,
                        PyGameButtons.RIGHTTHUMB: XboxControls.RIGHTTHUMB}
                        
    #setup xbox controller class
    def __init__(self,
                 joystickNo = 0,
                 deadzone = 0.1,
                 scale = 1,
                 invertYAxis = False):
        
        #persist values
        self.running = False
        self.joystickNo = joystickNo
        self.lowerDeadzone = deadzone * -1
        self.upperDeadzone = deadzone
        self.scale = scale
        self.invertYAxis = invertYAxis

        #setup controller properties
        self.controlValues = {self.XboxControls.LTHUMBX:0,
                              self.XboxControls.LTHUMBY:0,
                              self.XboxControls.RTHUMBX:0,
                              self.XboxControls.RTHUMBY:0,
                              self.XboxControls.RTRIGGER:0,
                              self.XboxControls.LTRIGGER:0,
                              self.XboxControls.A:0,
                              self.XboxControls.B:0,
                              self.XboxControls.X:0,
                              self.XboxControls.Y:0,
                              self.XboxControls.LB:0,
                              self.XboxControls.RB:0,
                              self.XboxControls.BACK:0,
                              self.XboxControls.START:0,
                              self.XboxControls.XBOX:0,
                              self.XboxControls.LEFTTHUMB:0,
                              self.XboxControls.RIGHTTHUMB:0,
                              self.XboxControls.DPAD:(0,0)}

        #setup pygame
        self._setupPygame(joystickNo)

    #Create controller properties
    @property
    def LTHUMBX(self):
        return self.controlValues[self.XboxControls.LTHUMBX]

    @property
    def LTHUMBY(self):
        return self.controlValues[self.XboxControls.LTHUMBY]

    @property
    def RTHUMBX(self):
        return self.controlValues[self.XboxControls.RTHUMBX]

    @property
    def RTHUMBY(self):
        return self.controlValues[self.XboxControls.RTHUMBY]

    @property
    def RTRIGGER(self):
        return self.controlValues[self.XboxControls.RTRIGGER]

    @property
    def LTRIGGER(self):
        return self.controlValues[self.XboxControls.LTRIGGER]

    @property
    def A(self):
        return self.controlValues[self.XboxControls.A]

    @property
    def B(self):
        return self.controlValues[self.XboxControls.B]

    @property
    def X(self):
        return self.controlValues[self.XboxControls.X]

    @property
    def Y(self):
        return self.controlValues[self.XboxControls.Y]

    @property
    def LB(self):
        return self.controlValues[self.XboxControls.LB]

    @property
    def RB(self):
        return self.controlValues[self.XboxControls.RB]

    @property
    def BACK(self):
        return self.controlValues[self.XboxControls.BACK]

    @property
    def START(self):
        return self.controlValues[self.XboxControls.START]

    @property
    def XBOX(self):
        return self.controlValues[self.XboxControls.XBOX]

    @property
    def LEFTTHUMB(self):
        return self.controlValues[self.XboxControls.LEFTTHUMB]

    @property
    def RIGHTTHUMB(self):
        return self.controlValues[self.XboxControls.RIGHTTHUMB]

    @property
    def DPAD(self):
        return self.controlValues[self.XboxControls.DPAD]

    #setup pygame
    def _setupPygame(self, joystickNo):
        # set SDL to use the dummy NULL video driver, so it doesn't need a windowing system.
        #os.putenv('SDL_VIDEODRIVER', 'fbcon')
        #os.environ["DISPLAY"] = ":0"
        os.environ["SDL_VIDEODRIVER"] = "dummy"
        # init pygame
        pygame.init()
        # create a 1x1 pixel screen, its not used so it doesnt matter
        pygame.display.init()
        #screen = pygame.display.set_mode((1, 1))
        # init the joystick control
        pygame.joystick.init()
        # how many joysticks are there
        #print pygame.joystick.get_count()
        # get the first joystick
        joy = pygame.joystick.Joystick(joystickNo)
        # init that joystick
        joy.init()


    #start the controller
    def _updateEvent(self):
        #react to the pygame events that come from the xbox controller
        for event in pygame.event.get():

            #thumb sticks, trigger buttons                    
            if event.type == JOYAXISMOTION:
                #is this axis on our xbox controller
                if event.axis in self.AXISCONTROLMAP:
                    #is this a y axis
                    yAxis = True if (event.axis == self.PyGameAxis.LTHUMBY or event.axis == self.PyGameAxis.RTHUMBY) else False
                    #update the control value
                    self.updateControlValue(self.AXISCONTROLMAP[event.axis],
                                            self._sortOutAxisValue(event.value, yAxis))
                #is this axis a trigger
                if event.axis in self.TRIGGERCONTROLMAP:
                    #update the control value
                    self.updateControlValue(self.TRIGGERCONTROLMAP[event.axis],
                                            self._sortOutTriggerValue(event.value))
                    
            #d pad
            elif event.type == JOYHATMOTION:
                #update control value
                self.updateControlValue(self.XboxControls.DPAD, event.value)

            #button pressed and unpressed
            elif event.type == JOYBUTTONUP or event.type == JOYBUTTONDOWN:
                #is this button on our xbox controller
                if event.button in self.BUTTONCONTROLMAP:
                    #update control value
                    self.updateControlValue(self.BUTTONCONTROLMAP[event.button],
                                            self._sortOutButtonValue(event.type))
        


    #updates a specific value in the control dictionary
    def updateControlValue(self, control, value):
        #if the value has changed update it
        if self.controlValues[control] != value:
            self.controlValues[control] = value
                
    #scales the axis values, applies the deadzone
    def _sortOutAxisValue(self, value, yAxis = False):
        #invert yAxis
        if yAxis and self.invertYAxis: value = value * -1
        #scale the value
        value = value * self.scale
        #apply the deadzone
        if value < self.upperDeadzone and value > self.lowerDeadzone: value = 0
        return value

    #turns the trigger value into something sensible and scales it
    def _sortOutTriggerValue(self, value):
        #trigger goes -1 to 1 (-1 is off, 1 is full on, half is 0) - I want this to be 0 - 1
        value = max(0,(value + 1) / 2)
        #scale the value
        value = value * self.scale
        return value

    #turns the event type (up/down) into a value
    def _sortOutButtonValue(self, eventType):
        #if the button is down its 1, if the button is up its 0
        value = 1 if eventType == JOYBUTTONDOWN else 0
        return value
    
#tests
if __name__ == '__main__':

    #setup xbox controller, set out the deadzone and scale, also invert the Y Axis (for some reason in Pygame negative is up - wierd! 
    xboxCont = XboxController(
        joystickNo = 0,
        deadzone = 0.1,
        scale = 1,
        invertYAxis = False)

    while True:
        time.sleep(0.1)
        message = str(xboxCont.LTHUMBX) + ","
        message = message + str(xboxCont.LTHUMBY) + ","
        message = message + str(xboxCont.RTHUMBX) + ","
        message = message + str(xboxCont.RTHUMBY) + ","
        message = message + str(xboxCont.RTRIGGER) + ","
        message = message + str(xboxCont.LTRIGGER) + ","
        message = message + str(xboxCont.A) + ","
        message = message + str(xboxCont.B) + ","
        message = message + str(xboxCont.X) + ","
        message = message + str(xboxCont.Y) + ","
        message = message + str(xboxCont.LB) + ","
        message = message + str(xboxCont.RB) + ","
        message = message + str(xboxCont.BACK) + ","
        message = message + str(xboxCont.START) + ","
        message = message + str(xboxCont.XBOX) + ","
        message = message + str(xboxCont.LEFTTHUMB) + ","
        message = message + str(xboxCont.RIGHTTHUMB) + ","
        message = message + str(xboxCont.DPAD) + ","
        print(message)
        xboxCont._updateEvent()
