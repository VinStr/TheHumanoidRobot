#!/usr/bin/env python

import rospy
from std_msgs.msg import Bool
from head_pkg.msg import Automation
import time

def onShutdown():
    print "ros stopping (callback)"

def talker():
    pub = rospy.Publisher('chatter', Automation, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rospy.on_shutdown(onShutdown)
    rate = rospy.Rate(10) # 10hz
    message = 0
    while not rospy.is_shutdown():
        message = Automation(None, 1, 0, 0)
        #rospy.loginfo(message)
        pub.publish(message)
        rate.sleep()
        time.sleep(0.5)

        message = Automation(None, 0, 1, 0)
        #rospy.loginfo(message)
        pub.publish(message)
        rate.sleep()
        time.sleep(0.5)

        message = Automation(None, 0, 0, 1)
        #rospy.loginfo(message)
        pub.publish(message)
        rate.sleep()
        time.sleep(0.5)

    print "ros stopping (while)"

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
