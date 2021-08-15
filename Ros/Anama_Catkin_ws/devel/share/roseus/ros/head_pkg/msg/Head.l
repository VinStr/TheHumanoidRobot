;; Auto-generated. Do not edit!


(when (boundp 'head_pkg::Head)
  (if (not (find-package "HEAD_PKG"))
    (make-package "HEAD_PKG"))
  (shadow 'Head (find-package "HEAD_PKG")))
(unless (find-package "HEAD_PKG::HEAD")
  (make-package "HEAD_PKG::HEAD"))

(in-package "ROS")
;;//! \htmlinclude Head.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass head_pkg::Head
  :super ros::object
  :slots (_header _eyesX _eyesY _jawX _jawY _eyeSkwint _jawZ _expression _blink _supprise _rightNose _leftNose ))

(defmethod head_pkg::Head
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:eyesX __eyesX) 0)
    ((:eyesY __eyesY) 0)
    ((:jawX __jawX) 0)
    ((:jawY __jawY) 0)
    ((:eyeSkwint __eyeSkwint) 0)
    ((:jawZ __jawZ) 0)
    ((:expression __expression) 0)
    ((:blink __blink) nil)
    ((:supprise __supprise) nil)
    ((:rightNose __rightNose) nil)
    ((:leftNose __leftNose) nil)
    )
   (send-super :init)
   (setq _header __header)
   (setq _eyesX (round __eyesX))
   (setq _eyesY (round __eyesY))
   (setq _jawX (round __jawX))
   (setq _jawY (round __jawY))
   (setq _eyeSkwint (round __eyeSkwint))
   (setq _jawZ (round __jawZ))
   (setq _expression (round __expression))
   (setq _blink __blink)
   (setq _supprise __supprise)
   (setq _rightNose __rightNose)
   (setq _leftNose __leftNose)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:eyesX
   (&optional __eyesX)
   (if __eyesX (setq _eyesX __eyesX)) _eyesX)
  (:eyesY
   (&optional __eyesY)
   (if __eyesY (setq _eyesY __eyesY)) _eyesY)
  (:jawX
   (&optional __jawX)
   (if __jawX (setq _jawX __jawX)) _jawX)
  (:jawY
   (&optional __jawY)
   (if __jawY (setq _jawY __jawY)) _jawY)
  (:eyeSkwint
   (&optional __eyeSkwint)
   (if __eyeSkwint (setq _eyeSkwint __eyeSkwint)) _eyeSkwint)
  (:jawZ
   (&optional __jawZ)
   (if __jawZ (setq _jawZ __jawZ)) _jawZ)
  (:expression
   (&optional __expression)
   (if __expression (setq _expression __expression)) _expression)
  (:blink
   (&optional __blink)
   (if __blink (setq _blink __blink)) _blink)
  (:supprise
   (&optional __supprise)
   (if __supprise (setq _supprise __supprise)) _supprise)
  (:rightNose
   (&optional __rightNose)
   (if __rightNose (setq _rightNose __rightNose)) _rightNose)
  (:leftNose
   (&optional __leftNose)
   (if __leftNose (setq _leftNose __leftNose)) _leftNose)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; int16 _eyesX
    2
    ;; int16 _eyesY
    2
    ;; int16 _jawX
    2
    ;; int16 _jawY
    2
    ;; int16 _eyeSkwint
    2
    ;; int16 _jawZ
    2
    ;; int16 _expression
    2
    ;; bool _blink
    1
    ;; bool _supprise
    1
    ;; bool _rightNose
    1
    ;; bool _leftNose
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; int16 _eyesX
       (write-word _eyesX s)
     ;; int16 _eyesY
       (write-word _eyesY s)
     ;; int16 _jawX
       (write-word _jawX s)
     ;; int16 _jawY
       (write-word _jawY s)
     ;; int16 _eyeSkwint
       (write-word _eyeSkwint s)
     ;; int16 _jawZ
       (write-word _jawZ s)
     ;; int16 _expression
       (write-word _expression s)
     ;; bool _blink
       (if _blink (write-byte -1 s) (write-byte 0 s))
     ;; bool _supprise
       (if _supprise (write-byte -1 s) (write-byte 0 s))
     ;; bool _rightNose
       (if _rightNose (write-byte -1 s) (write-byte 0 s))
     ;; bool _leftNose
       (if _leftNose (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; int16 _eyesX
     (setq _eyesX (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _eyesY
     (setq _eyesY (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _jawX
     (setq _jawX (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _jawY
     (setq _jawY (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _eyeSkwint
     (setq _eyeSkwint (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _jawZ
     (setq _jawZ (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _expression
     (setq _expression (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; bool _blink
     (setq _blink (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _supprise
     (setq _supprise (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _rightNose
     (setq _rightNose (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _leftNose
     (setq _leftNose (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get head_pkg::Head :md5sum-) "802348f5a2f1e8dfd50efdc8d6faf838")
(setf (get head_pkg::Head :datatype-) "head_pkg/Head")
(setf (get head_pkg::Head :definition-)
      "Header header
int16 eyesX
int16 eyesY
int16 jawX
int16 jawY
int16 eyeSkwint
int16 jawZ
int16 expression
bool blink
bool supprise
bool rightNose
bool leftNose
================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

")



(provide :head_pkg/Head "802348f5a2f1e8dfd50efdc8d6faf838")


