#!/bin/sh
. devel/setup.bash
roslaunch head_pkg full_control.launch &
sudo su <<EOF
. devel/setup.bash
rosrun head_pkg controllInterfaceRev2Neck.py
EOF