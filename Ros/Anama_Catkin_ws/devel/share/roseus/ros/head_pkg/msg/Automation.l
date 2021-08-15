;; Auto-generated. Do not edit!


(when (boundp 'head_pkg::Automation)
  (if (not (find-package "HEAD_PKG"))
    (make-package "HEAD_PKG"))
  (shadow 'Automation (find-package "HEAD_PKG")))
(unless (find-package "HEAD_PKG::AUTOMATION")
  (make-package "HEAD_PKG::AUTOMATION"))

(in-package "ROS")
;;//! \htmlinclude Automation.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass head_pkg::Automation
  :super ros::object
  :slots (_header _relay1 _relay2 _relay3 ))

(defmethod head_pkg::Automation
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:relay1 __relay1) nil)
    ((:relay2 __relay2) nil)
    ((:relay3 __relay3) nil)
    )
   (send-super :init)
   (setq _header __header)
   (setq _relay1 __relay1)
   (setq _relay2 __relay2)
   (setq _relay3 __relay3)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:relay1
   (&optional __relay1)
   (if __relay1 (setq _relay1 __relay1)) _relay1)
  (:relay2
   (&optional __relay2)
   (if __relay2 (setq _relay2 __relay2)) _relay2)
  (:relay3
   (&optional __relay3)
   (if __relay3 (setq _relay3 __relay3)) _relay3)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; bool _relay1
    1
    ;; bool _relay2
    1
    ;; bool _relay3
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; bool _relay1
       (if _relay1 (write-byte -1 s) (write-byte 0 s))
     ;; bool _relay2
       (if _relay2 (write-byte -1 s) (write-byte 0 s))
     ;; bool _relay3
       (if _relay3 (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; bool _relay1
     (setq _relay1 (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _relay2
     (setq _relay2 (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _relay3
     (setq _relay3 (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get head_pkg::Automation :md5sum-) "bb789613f23439dcb13bc2641016e45e")
(setf (get head_pkg::Automation :datatype-) "head_pkg/Automation")
(setf (get head_pkg::Automation :definition-)
      "Header header
bool relay1
bool relay2
bool relay3
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



(provide :head_pkg/Automation "bb789613f23439dcb13bc2641016e45e")


