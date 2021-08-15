#!/usr/bin/env python

import serial
from serial.tools import list_ports
import time

if __name__ == '__main__':

    for port in list_ports.comports(include_links=False):
            print(str(port) + " : " + str(port.location))
            #if port.location == "1-1.3":
            #    portAdress = str(port.device)