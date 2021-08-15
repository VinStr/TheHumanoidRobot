;; Auto-generated. Do not edit!


(when (boundp 'head_pkg::Neck)
  (if (not (find-package "HEAD_PKG"))
    (make-package "HEAD_PKG"))
  (shadow 'Neck (find-package "HEAD_PKG")))
(unless (find-package "HEAD_PKG::NECK")
  (make-package "HEAD_PKG::NECK"))

(in-package "ROS")
;;//! \htmlinclude Neck.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass head_pkg::Neck
  :super ros::object
  :slots (_header _NeckTurnPos _HeadPitch _HeadRoll _SensPitch _SensRoll _ToungeExpression ))

(defmethod head_pkg::Neck
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:NeckTurnPos __NeckTurnPos) 0)
    ((:HeadPitch __HeadPitch) 0)
    ((:HeadRoll __HeadRoll) 0)
    ((:SensPitch __SensPitch) 0.0)
    ((:SensRoll __SensRoll) 0.0)
    ((:ToungeExpression __ToungeExpression) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _NeckTurnPos (round __NeckTurnPos))
   (setq _HeadPitch (round __HeadPitch))
   (setq _HeadRoll (round __HeadRoll))
   (setq _SensPitch (float __SensPitch))
   (setq _SensRoll (float __SensRoll))
   (setq _ToungeExpression (round __ToungeExpression))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:NeckTurnPos
   (&optional __NeckTurnPos)
   (if __NeckTurnPos (setq _NeckTurnPos __NeckTurnPos)) _NeckTurnPos)
  (:HeadPitch
   (&optional __HeadPitch)
   (if __HeadPitch (setq _HeadPitch __HeadPitch)) _HeadPitch)
  (:HeadRoll
   (&optional __HeadRoll)
   (if __HeadRoll (setq _HeadRoll __HeadRoll)) _HeadRoll)
  (:SensPitch
   (&optional __SensPitch)
   (if __SensPitch (setq _SensPitch __SensPitch)) _SensPitch)
  (:SensRoll
   (&optional __SensRoll)
   (if __SensRoll (setq _SensRoll __SensRoll)) _SensRoll)
  (:ToungeExpression
   (&optional __ToungeExpression)
   (if __ToungeExpression (setq _ToungeExpression __ToungeExpression)) _ToungeExpression)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; int16 _NeckTurnPos
    2
    ;; int16 _HeadPitch
    2
    ;; int16 _HeadRoll
    2
    ;; float32 _SensPitch
    4
    ;; float32 _SensRoll
    4
    ;; int16 _ToungeExpression
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; int16 _NeckTurnPos
       (write-word _NeckTurnPos s)
     ;; int16 _HeadPitch
       (write-word _HeadPitch s)
     ;; int16 _HeadRoll
       (write-word _HeadRoll s)
     ;; float32 _SensPitch
       (sys::poke _SensPitch (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _SensRoll
       (sys::poke _SensRoll (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; int16 _ToungeExpression
       (write-word _ToungeExpression s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; int16 _NeckTurnPos
     (setq _NeckTurnPos (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _HeadPitch
     (setq _HeadPitch (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _HeadRoll
     (setq _HeadRoll (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; float32 _SensPitch
     (setq _SensPitch (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _SensRoll
     (setq _SensRoll (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; int16 _ToungeExpression
     (setq _ToungeExpression (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get head_pkg::Neck :md5sum-) "ee86276cb042e4ad198a659440dd1e51")
(setf (get head_pkg::Neck :datatype-) "head_pkg/Neck")
(setf (get head_pkg::Neck :definition-)
      "Header header
int16 NeckTurnPos
int16 HeadPitch
int16 HeadRoll
float32 SensPitch
float32 SensRoll
int16 ToungeExpression
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



(provide :head_pkg/Neck "ee86276cb042e4ad198a659440dd1e51")


