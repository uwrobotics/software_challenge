;; Auto-generated. Do not edit!


(when (boundp 'software_training_assignment::Distance)
  (if (not (find-package "SOFTWARE_TRAINING_ASSIGNMENT"))
    (make-package "SOFTWARE_TRAINING_ASSIGNMENT"))
  (shadow 'Distance (find-package "SOFTWARE_TRAINING_ASSIGNMENT")))
(unless (find-package "SOFTWARE_TRAINING_ASSIGNMENT::DISTANCE")
  (make-package "SOFTWARE_TRAINING_ASSIGNMENT::DISTANCE"))

(in-package "ROS")
;;//! \htmlinclude Distance.msg.html


(defclass software_training_assignment::Distance
  :super ros::object
  :slots (_xDistance _yDistance _distance ))

(defmethod software_training_assignment::Distance
  (:init
   (&key
    ((:xDistance __xDistance) 0)
    ((:yDistance __yDistance) 0)
    ((:distance __distance) 0)
    )
   (send-super :init)
   (setq _xDistance (round __xDistance))
   (setq _yDistance (round __yDistance))
   (setq _distance (round __distance))
   self)
  (:xDistance
   (&optional __xDistance)
   (if __xDistance (setq _xDistance __xDistance)) _xDistance)
  (:yDistance
   (&optional __yDistance)
   (if __yDistance (setq _yDistance __yDistance)) _yDistance)
  (:distance
   (&optional __distance)
   (if __distance (setq _distance __distance)) _distance)
  (:serialization-length
   ()
   (+
    ;; uint32 _xDistance
    4
    ;; uint32 _yDistance
    4
    ;; uint32 _distance
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _xDistance
       (write-long _xDistance s)
     ;; uint32 _yDistance
       (write-long _yDistance s)
     ;; uint32 _distance
       (write-long _distance s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _xDistance
     (setq _xDistance (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _yDistance
     (setq _yDistance (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _distance
     (setq _distance (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get software_training_assignment::Distance :md5sum-) "bd9e80af1a4aa422f1993f6c21a12fac")
(setf (get software_training_assignment::Distance :datatype-) "software_training_assignment/Distance")
(setf (get software_training_assignment::Distance :definition-)
      "uint32 xDistance
uint32 yDistance
uint32 distance
")



(provide :software_training_assignment/Distance "bd9e80af1a4aa422f1993f6c21a12fac")


