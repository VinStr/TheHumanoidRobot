# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "head_pkg: 3 messages, 0 services")

set(MSG_I_FLAGS "-Ihead_pkg:/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(head_pkg_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Neck.msg" NAME_WE)
add_custom_target(_head_pkg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "head_pkg" "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Neck.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Automation.msg" NAME_WE)
add_custom_target(_head_pkg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "head_pkg" "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Automation.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Head.msg" NAME_WE)
add_custom_target(_head_pkg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "head_pkg" "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Head.msg" "std_msgs/Header"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(head_pkg
  "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Neck.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/head_pkg
)
_generate_msg_cpp(head_pkg
  "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Automation.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/head_pkg
)
_generate_msg_cpp(head_pkg
  "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Head.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/head_pkg
)

### Generating Services

### Generating Module File
_generate_module_cpp(head_pkg
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/head_pkg
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(head_pkg_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(head_pkg_generate_messages head_pkg_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Neck.msg" NAME_WE)
add_dependencies(head_pkg_generate_messages_cpp _head_pkg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Automation.msg" NAME_WE)
add_dependencies(head_pkg_generate_messages_cpp _head_pkg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Head.msg" NAME_WE)
add_dependencies(head_pkg_generate_messages_cpp _head_pkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(head_pkg_gencpp)
add_dependencies(head_pkg_gencpp head_pkg_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS head_pkg_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(head_pkg
  "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Neck.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/head_pkg
)
_generate_msg_eus(head_pkg
  "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Automation.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/head_pkg
)
_generate_msg_eus(head_pkg
  "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Head.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/head_pkg
)

### Generating Services

### Generating Module File
_generate_module_eus(head_pkg
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/head_pkg
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(head_pkg_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(head_pkg_generate_messages head_pkg_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Neck.msg" NAME_WE)
add_dependencies(head_pkg_generate_messages_eus _head_pkg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Automation.msg" NAME_WE)
add_dependencies(head_pkg_generate_messages_eus _head_pkg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Head.msg" NAME_WE)
add_dependencies(head_pkg_generate_messages_eus _head_pkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(head_pkg_geneus)
add_dependencies(head_pkg_geneus head_pkg_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS head_pkg_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(head_pkg
  "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Neck.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/head_pkg
)
_generate_msg_lisp(head_pkg
  "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Automation.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/head_pkg
)
_generate_msg_lisp(head_pkg
  "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Head.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/head_pkg
)

### Generating Services

### Generating Module File
_generate_module_lisp(head_pkg
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/head_pkg
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(head_pkg_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(head_pkg_generate_messages head_pkg_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Neck.msg" NAME_WE)
add_dependencies(head_pkg_generate_messages_lisp _head_pkg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Automation.msg" NAME_WE)
add_dependencies(head_pkg_generate_messages_lisp _head_pkg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Head.msg" NAME_WE)
add_dependencies(head_pkg_generate_messages_lisp _head_pkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(head_pkg_genlisp)
add_dependencies(head_pkg_genlisp head_pkg_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS head_pkg_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(head_pkg
  "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Neck.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/head_pkg
)
_generate_msg_nodejs(head_pkg
  "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Automation.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/head_pkg
)
_generate_msg_nodejs(head_pkg
  "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Head.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/head_pkg
)

### Generating Services

### Generating Module File
_generate_module_nodejs(head_pkg
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/head_pkg
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(head_pkg_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(head_pkg_generate_messages head_pkg_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Neck.msg" NAME_WE)
add_dependencies(head_pkg_generate_messages_nodejs _head_pkg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Automation.msg" NAME_WE)
add_dependencies(head_pkg_generate_messages_nodejs _head_pkg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Head.msg" NAME_WE)
add_dependencies(head_pkg_generate_messages_nodejs _head_pkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(head_pkg_gennodejs)
add_dependencies(head_pkg_gennodejs head_pkg_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS head_pkg_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(head_pkg
  "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Neck.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/head_pkg
)
_generate_msg_py(head_pkg
  "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Automation.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/head_pkg
)
_generate_msg_py(head_pkg
  "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Head.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/head_pkg
)

### Generating Services

### Generating Module File
_generate_module_py(head_pkg
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/head_pkg
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(head_pkg_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(head_pkg_generate_messages head_pkg_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Neck.msg" NAME_WE)
add_dependencies(head_pkg_generate_messages_py _head_pkg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Automation.msg" NAME_WE)
add_dependencies(head_pkg_generate_messages_py _head_pkg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/Desktop/anamatronic/Ros/Anama_Catkin_ws/src/head_pkg/msg/Head.msg" NAME_WE)
add_dependencies(head_pkg_generate_messages_py _head_pkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(head_pkg_genpy)
add_dependencies(head_pkg_genpy head_pkg_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS head_pkg_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/head_pkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/head_pkg
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(head_pkg_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/head_pkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/head_pkg
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(head_pkg_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/head_pkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/head_pkg
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(head_pkg_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/head_pkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/head_pkg
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(head_pkg_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/head_pkg)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/head_pkg\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/head_pkg
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(head_pkg_generate_messages_py std_msgs_generate_messages_py)
endif()
