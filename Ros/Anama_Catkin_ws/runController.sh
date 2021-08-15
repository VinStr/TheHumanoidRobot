#!/bin/sh
sudo su <<EOF
. devel/setup.bash
rosrun head_pkg controllInterfaceRev2Neck.py
EOF