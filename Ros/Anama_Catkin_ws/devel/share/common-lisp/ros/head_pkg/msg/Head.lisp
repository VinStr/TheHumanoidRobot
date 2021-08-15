; Auto-generated. Do not edit!


(cl:in-package head_pkg-msg)


;//! \htmlinclude Head.msg.html

(cl:defclass <Head> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (eyesX
    :reader eyesX
    :initarg :eyesX
    :type cl:fixnum
    :initform 0)
   (eyesY
    :reader eyesY
    :initarg :eyesY
    :type cl:fixnum
    :initform 0)
   (jawX
    :reader jawX
    :initarg :jawX
    :type cl:fixnum
    :initform 0)
   (jawY
    :reader jawY
    :initarg :jawY
    :type cl:fixnum
    :initform 0)
   (eyeSkwint
    :reader eyeSkwint
    :initarg :eyeSkwint
    :type cl:fixnum
    :initform 0)
   (jawZ
    :reader jawZ
    :initarg :jawZ
    :type cl:fixnum
    :initform 0)
   (expression
    :reader expression
    :initarg :expression
    :type cl:fixnum
    :initform 0)
   (blink
    :reader blink
    :initarg :blink
    :type cl:boolean
    :initform cl:nil)
   (supprise
    :reader supprise
    :initarg :supprise
    :type cl:boolean
    :initform cl:nil)
   (rightNose
    :reader rightNose
    :initarg :rightNose
    :type cl:boolean
    :initform cl:nil)
   (leftNose
    :reader leftNose
    :initarg :leftNose
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass Head (<Head>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Head>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Head)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name head_pkg-msg:<Head> is deprecated: use head_pkg-msg:Head instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <Head>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader head_pkg-msg:header-val is deprecated.  Use head_pkg-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'eyesX-val :lambda-list '(m))
(cl:defmethod eyesX-val ((m <Head>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader head_pkg-msg:eyesX-val is deprecated.  Use head_pkg-msg:eyesX instead.")
  (eyesX m))

(cl:ensure-generic-function 'eyesY-val :lambda-list '(m))
(cl:defmethod eyesY-val ((m <Head>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader head_pkg-msg:eyesY-val is deprecated.  Use head_pkg-msg:eyesY instead.")
  (eyesY m))

(cl:ensure-generic-function 'jawX-val :lambda-list '(m))
(cl:defmethod jawX-val ((m <Head>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader head_pkg-msg:jawX-val is deprecated.  Use head_pkg-msg:jawX instead.")
  (jawX m))

(cl:ensure-generic-function 'jawY-val :lambda-list '(m))
(cl:defmethod jawY-val ((m <Head>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader head_pkg-msg:jawY-val is deprecated.  Use head_pkg-msg:jawY instead.")
  (jawY m))

(cl:ensure-generic-function 'eyeSkwint-val :lambda-list '(m))
(cl:defmethod eyeSkwint-val ((m <Head>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader head_pkg-msg:eyeSkwint-val is deprecated.  Use head_pkg-msg:eyeSkwint instead.")
  (eyeSkwint m))

(cl:ensure-generic-function 'jawZ-val :lambda-list '(m))
(cl:defmethod jawZ-val ((m <Head>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader head_pkg-msg:jawZ-val is deprecated.  Use head_pkg-msg:jawZ instead.")
  (jawZ m))

(cl:ensure-generic-function 'expression-val :lambda-list '(m))
(cl:defmethod expression-val ((m <Head>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader head_pkg-msg:expression-val is deprecated.  Use head_pkg-msg:expression instead.")
  (expression m))

(cl:ensure-generic-function 'blink-val :lambda-list '(m))
(cl:defmethod blink-val ((m <Head>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader head_pkg-msg:blink-val is deprecated.  Use head_pkg-msg:blink instead.")
  (blink m))

(cl:ensure-generic-function 'supprise-val :lambda-list '(m))
(cl:defmethod supprise-val ((m <Head>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader head_pkg-msg:supprise-val is deprecated.  Use head_pkg-msg:supprise instead.")
  (supprise m))

(cl:ensure-generic-function 'rightNose-val :lambda-list '(m))
(cl:defmethod rightNose-val ((m <Head>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader head_pkg-msg:rightNose-val is deprecated.  Use head_pkg-msg:rightNose instead.")
  (rightNose m))

(cl:ensure-generic-function 'leftNose-val :lambda-list '(m))
(cl:defmethod leftNose-val ((m <Head>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader head_pkg-msg:leftNose-val is deprecated.  Use head_pkg-msg:leftNose instead.")
  (leftNose m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Head>) ostream)
  "Serializes a message object of type '<Head>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'eyesX)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'eyesY)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'jawX)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'jawY)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'eyeSkwint)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'jawZ)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'expression)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'blink) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'supprise) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'rightNose) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'leftNose) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Head>) istream)
  "Deserializes a message object of type '<Head>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'eyesX) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'eyesY) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'jawX) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'jawY) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'eyeSkwint) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'jawZ) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'expression) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:setf (cl:slot-value msg 'blink) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'supprise) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'rightNose) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'leftNose) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Head>)))
  "Returns string type for a message object of type '<Head>"
  "head_pkg/Head")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Head)))
  "Returns string type for a message object of type 'Head"
  "head_pkg/Head")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Head>)))
  "Returns md5sum for a message object of type '<Head>"
  "802348f5a2f1e8dfd50efdc8d6faf838")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Head)))
  "Returns md5sum for a message object of type 'Head"
  "802348f5a2f1e8dfd50efdc8d6faf838")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Head>)))
  "Returns full string definition for message of type '<Head>"
  (cl:format cl:nil "Header header~%int16 eyesX~%int16 eyesY~%int16 jawX~%int16 jawY~%int16 eyeSkwint~%int16 jawZ~%int16 expression~%bool blink~%bool supprise~%bool rightNose~%bool leftNose~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Head)))
  "Returns full string definition for message of type 'Head"
  (cl:format cl:nil "Header header~%int16 eyesX~%int16 eyesY~%int16 jawX~%int16 jawY~%int16 eyeSkwint~%int16 jawZ~%int16 expression~%bool blink~%bool supprise~%bool rightNose~%bool leftNose~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Head>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     2
     2
     2
     2
     2
     2
     2
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Head>))
  "Converts a ROS message object to a list"
  (cl:list 'Head
    (cl:cons ':header (header msg))
    (cl:cons ':eyesX (eyesX msg))
    (cl:cons ':eyesY (eyesY msg))
    (cl:cons ':jawX (jawX msg))
    (cl:cons ':jawY (jawY msg))
    (cl:cons ':eyeSkwint (eyeSkwint msg))
    (cl:cons ':jawZ (jawZ msg))
    (cl:cons ':expression (expression msg))
    (cl:cons ':blink (blink msg))
    (cl:cons ':supprise (supprise msg))
    (cl:cons ':rightNose (rightNose msg))
    (cl:cons ':leftNose (leftNose msg))
))
