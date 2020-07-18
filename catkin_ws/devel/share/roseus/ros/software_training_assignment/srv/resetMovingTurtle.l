;; Auto-generated. Do not edit!


(when (boundp 'software_training_assignment::resetMovingTurtle)
  (if (not (find-package "SOFTWARE_TRAINING_ASSIGNMENT"))
    (make-package "SOFTWARE_TRAINING_ASSIGNMENT"))
  (shadow 'resetMovingTurtle (find-package "SOFTWARE_TRAINING_ASSIGNMENT")))
(unless (find-package "SOFTWARE_TRAINING_ASSIGNMENT::RESETMOVINGTURTLE")
  (make-package "SOFTWARE_TRAINING_ASSIGNMENT::RESETMOVINGTURTLE"))
(unless (find-package "SOFTWARE_TRAINING_ASSIGNMENT::RESETMOVINGTURTLEREQUEST")
  (make-package "SOFTWARE_TRAINING_ASSIGNMENT::RESETMOVINGTURTLEREQUEST"))
(unless (find-package "SOFTWARE_TRAINING_ASSIGNMENT::RESETMOVINGTURTLERESPONSE")
  (make-package "SOFTWARE_TRAINING_ASSIGNMENT::RESETMOVINGTURTLERESPONSE"))

(in-package "ROS")





(defclass software_training_assignment::resetMovingTurtleRequest
  :super ros::object
  :slots ())

(defmethod software_training_assignment::resetMovingTurtleRequest
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass software_training_assignment::resetMovingTurtleResponse
  :super ros::object
  :slots ())

(defmethod software_training_assignment::resetMovingTurtleResponse
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass software_training_assignment::resetMovingTurtle
  :super ros::object
  :slots ())

(setf (get software_training_assignment::resetMovingTurtle :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get software_training_assignment::resetMovingTurtle :datatype-) "software_training_assignment/resetMovingTurtle")
(setf (get software_training_assignment::resetMovingTurtle :request) software_training_assignment::resetMovingTurtleRequest)
(setf (get software_training_assignment::resetMovingTurtle :response) software_training_assignment::resetMovingTurtleResponse)

(defmethod software_training_assignment::resetMovingTurtleRequest
  (:response () (instance software_training_assignment::resetMovingTurtleResponse :init)))

(setf (get software_training_assignment::resetMovingTurtleRequest :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get software_training_assignment::resetMovingTurtleRequest :datatype-) "software_training_assignment/resetMovingTurtleRequest")
(setf (get software_training_assignment::resetMovingTurtleRequest :definition-)
      "---
")

(setf (get software_training_assignment::resetMovingTurtleResponse :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get software_training_assignment::resetMovingTurtleResponse :datatype-) "software_training_assignment/resetMovingTurtleResponse")
(setf (get software_training_assignment::resetMovingTurtleResponse :definition-)
      "---
")



(provide :software_training_assignment/resetMovingTurtle "d41d8cd98f00b204e9800998ecf8427e")


