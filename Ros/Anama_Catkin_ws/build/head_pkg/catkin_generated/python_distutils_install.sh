#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/install/lib/python2.7/dist-packages:/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/build" \
    "/usr/bin/python2" \
    "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/setup.py" \
    build --build-base "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/build/head_pkg" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/install" --install-scripts="/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/install/bin"
