; Auto-generated. Do not edit!


(cl:in-package head_pkg-msg)


;//! \htmlinclude Neck.msg.html

(cl:defclass <Neck> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (NeckTurnPos
    :reader NeckTurnPos
    :initarg :NeckTurnPos
    :type cl:fixnum
    :initform 0)
   (HeadPitch
    :reader HeadPitch
    :initarg :HeadPitch
    :type cl:fixnum
    :initform 0)
   (HeadRoll
    :reader HeadRoll
    :initarg :HeadRoll
    :type cl:fixnum
    :initform 0)
   (SensPitch
    :reader SensPitch
    :initarg :SensPitch
    :type cl:float
    :initform 0.0)
   (SensRoll
    :reader SensRoll
    :initarg :SensRoll
    :type cl:float
    :initform 0.0)
   (ToungeExpression
    :reader ToungeExpression
    :initarg :ToungeExpression
    :type cl:fixnum
    :initform 0))
)

(cl:defclass Neck (<Neck>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Neck>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Neck)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name head_pkg-msg:<Neck> is deprecated: use head_pkg-msg:Neck instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <Neck>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader head_pkg-msg:header-val is deprecated.  Use head_pkg-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'NeckTurnPos-val :lambda-list '(m))
(cl:defmethod NeckTurnPos-val ((m <Neck>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader head_pkg-msg:NeckTurnPos-val is deprecated.  Use head_pkg-msg:NeckTurnPos instead.")
  (NeckTurnPos m))

(cl:ensure-generic-function 'HeadPitch-val :lambda-list '(m))
(cl:defmethod HeadPitch-val ((m <Neck>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader head_pkg-msg:HeadPitch-val is deprecated.  Use head_pkg-msg:HeadPitch instead.")
  (HeadPitch m))

(cl:ensure-generic-function 'HeadRoll-val :lambda-list '(m))
(cl:defmethod HeadRoll-val ((m <Neck>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader head_pkg-msg:HeadRoll-val is deprecated.  Use head_pkg-msg:HeadRoll instead.")
  (HeadRoll m))

(cl:ensure-generic-function 'SensPitch-val :lambda-list '(m))
(cl:defmethod SensPitch-val ((m <Neck>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader head_pkg-msg:SensPitch-val is deprecated.  Use head_pkg-msg:SensPitch instead.")
  (SensPitch m))

(cl:ensure-generic-function 'SensRoll-val :lambda-list '(m))
(cl:defmethod SensRoll-val ((m <Neck>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader head_pkg-msg:SensRoll-val is deprecated.  Use head_pkg-msg:SensRoll instead.")
  (SensRoll m))

(cl:ensure-generic-function 'ToungeExpression-val :lambda-list '(m))
(cl:defmethod ToungeExpression-val ((m <Neck>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader head_pkg-msg:ToungeExpression-val is deprecated.  Use head_pkg-msg:ToungeExpression instead.")
  (ToungeExpression m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Neck>) ostream)
  "Serializes a message object of type '<Neck>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'NeckTurnPos)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'HeadPitch)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'HeadRoll)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'SensPitch))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'SensRoll))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'ToungeExpression)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Neck>) istream)
  "Deserializes a message object of type '<Neck>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'NeckTurnPos) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'HeadPitch) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'HeadRoll) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'SensPitch) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'SensRoll) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ToungeExpression) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Neck>)))
  "Returns string type for a message object of type '<Neck>"
  "head_pkg/Neck")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Neck)))
  "Returns string type for a message object of type 'Neck"
  "head_pkg/Neck")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Neck>)))
  "Returns md5sum for a message object of type '<Neck>"
  "ee86276cb042e4ad198a659440dd1e51")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Neck)))
  "Returns md5sum for a message object of type 'Neck"
  "ee86276cb042e4ad198a659440dd1e51")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Neck>)))
  "Returns full string definition for message of type '<Neck>"
  (cl:format cl:nil "Header header~%int16 NeckTurnPos~%int16 HeadPitch~%int16 HeadRoll~%float32 SensPitch~%float32 SensRoll~%int16 ToungeExpression~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Neck)))
  "Returns full string definition for message of type 'Neck"
  (cl:format cl:nil "Header header~%int16 NeckTurnPos~%int16 HeadPitch~%int16 HeadRoll~%float32 SensPitch~%float32 SensRoll~%int16 ToungeExpression~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Neck>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     2
     2
     2
     4
     4
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Neck>))
  "Converts a ROS message object to a list"
  (cl:list 'Neck
    (cl:cons ':header (header msg))
    (cl:cons ':NeckTurnPos (NeckTurnPos msg))
    (cl:cons ':HeadPitch (HeadPitch msg))
    (cl:cons ':HeadRoll (HeadRoll msg))
    (cl:cons ':SensPitch (SensPitch msg))
    (cl:cons ':SensRoll (SensRoll msg))
    (cl:cons ':ToungeExpression (ToungeExpression msg))
))
