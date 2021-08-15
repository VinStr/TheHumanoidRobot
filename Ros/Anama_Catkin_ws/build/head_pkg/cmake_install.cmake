# Install script for directory: /home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/build/head_pkg/catkin_generated/safe_execute_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/head_pkg/msg" TYPE FILE FILES
    "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Automation.msg"
    "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Head.msg"
    "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Neck.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/head_pkg/cmake" TYPE FILE FILES "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/build/head_pkg/catkin_generated/installspace/head_pkg-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/devel/include/head_pkg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/devel/share/roseus/ros/head_pkg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/devel/share/common-lisp/ros/head_pkg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/devel/share/gennodejs/ros/head_pkg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/devel/lib/python2.7/dist-packages/head_pkg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/devel/lib/python2.7/dist-packages/head_pkg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/build/head_pkg/catkin_generated/installspace/head_pkg.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/head_pkg/cmake" TYPE FILE FILES "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/build/head_pkg/catkin_generated/installspace/head_pkg-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/head_pkg/cmake" TYPE FILE FILES
    "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/build/head_pkg/catkin_generated/installspace/head_pkgConfig.cmake"
    "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/build/head_pkg/catkin_generated/installspace/head_pkgConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/head_pkg" TYPE FILE FILES "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/head_pkg" TYPE PROGRAM FILES "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/build/head_pkg/catkin_generated/installspace/HeadInterface.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/head_pkg" TYPE PROGRAM FILES "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/build/head_pkg/catkin_generated/installspace/NeckInterface.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/head_pkg" TYPE PROGRAM FILES "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/build/head_pkg/catkin_generated/installspace/speechNode.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/head_pkg" TYPE PROGRAM FILES "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/build/head_pkg/catkin_generated/installspace/controllInterfaceRev2.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/head_pkg" TYPE PROGRAM FILES "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/build/head_pkg/catkin_generated/installspace/controllInterfaceRev2Neck.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/head_pkg" TYPE PROGRAM FILES "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/build/head_pkg/catkin_generated/installspace/controllInterface.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/head_pkg" TYPE PROGRAM FILES "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/build/head_pkg/catkin_generated/installspace/listener.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/head_pkg" TYPE PROGRAM FILES "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/build/head_pkg/catkin_generated/installspace/talker.py")
endif()

