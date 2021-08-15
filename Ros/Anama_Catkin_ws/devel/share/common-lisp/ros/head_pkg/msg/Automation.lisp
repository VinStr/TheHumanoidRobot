; Auto-generated. Do not edit!


(cl:in-package head_pkg-msg)


;//! \htmlinclude Automation.msg.html

(cl:defclass <Automation> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (relay1
    :reader relay1
    :initarg :relay1
    :type cl:boolean
    :initform cl:nil)
   (relay2
    :reader relay2
    :initarg :relay2
    :type cl:boolean
    :initform cl:nil)
   (relay3
    :reader relay3
    :initarg :relay3
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass Automation (<Automation>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Automation>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Automation)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name head_pkg-msg:<Automation> is deprecated: use head_pkg-msg:Automation instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <Automation>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader head_pkg-msg:header-val is deprecated.  Use head_pkg-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'relay1-val :lambda-list '(m))
(cl:defmethod relay1-val ((m <Automation>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader head_pkg-msg:relay1-val is deprecated.  Use head_pkg-msg:relay1 instead.")
  (relay1 m))

(cl:ensure-generic-function 'relay2-val :lambda-list '(m))
(cl:defmethod relay2-val ((m <Automation>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader head_pkg-msg:relay2-val is deprecated.  Use head_pkg-msg:relay2 instead.")
  (relay2 m))

(cl:ensure-generic-function 'relay3-val :lambda-list '(m))
(cl:defmethod relay3-val ((m <Automation>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader head_pkg-msg:relay3-val is deprecated.  Use head_pkg-msg:relay3 instead.")
  (relay3 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Automation>) ostream)
  "Serializes a message object of type '<Automation>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'relay1) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'relay2) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'relay3) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Automation>) istream)
  "Deserializes a message object of type '<Automation>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:slot-value msg 'relay1) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'relay2) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'relay3) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Automation>)))
  "Returns string type for a message object of type '<Automation>"
  "head_pkg/Automation")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Automation)))
  "Returns string type for a message object of type 'Automation"
  "head_pkg/Automation")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Automation>)))
  "Returns md5sum for a message object of type '<Automation>"
  "bb789613f23439dcb13bc2641016e45e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Automation)))
  "Returns md5sum for a message object of type 'Automation"
  "bb789613f23439dcb13bc2641016e45e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Automation>)))
  "Returns full string definition for message of type '<Automation>"
  (cl:format cl:nil "Header header~%bool relay1~%bool relay2~%bool relay3~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Automation)))
  "Returns full string definition for message of type 'Automation"
  (cl:format cl:nil "Header header~%bool relay1~%bool relay2~%bool relay3~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Automation>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Automation>))
  "Converts a ROS message object to a list"
  (cl:list 'Automation
    (cl:cons ':header (header msg))
    (cl:cons ':relay1 (relay1 msg))
    (cl:cons ':relay2 (relay2 msg))
    (cl:cons ':relay3 (relay3 msg))
))
