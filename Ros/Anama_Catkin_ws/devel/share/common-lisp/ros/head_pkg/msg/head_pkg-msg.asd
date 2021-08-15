
(cl:in-package :asdf)

(defsystem "head_pkg-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "Automation" :depends-on ("_package_Automation"))
    (:file "_package_Automation" :depends-on ("_package"))
    (:file "Head" :depends-on ("_package_Head"))
    (:file "_package_Head" :depends-on ("_package"))
    (:file "Neck" :depends-on ("_package_Neck"))
    (:file "_package_Neck" :depends-on ("_package"))
  ))