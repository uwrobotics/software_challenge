
(cl:in-package :asdf)

(defsystem "software_training_assignment-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "resetMovingTurtle" :depends-on ("_package_resetMovingTurtle"))
    (:file "_package_resetMovingTurtle" :depends-on ("_package"))
  ))