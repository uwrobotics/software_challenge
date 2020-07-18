; Auto-generated. Do not edit!


(cl:in-package software_training_assignment-msg)


;//! \htmlinclude Distance.msg.html

(cl:defclass <Distance> (roslisp-msg-protocol:ros-message)
  ((xDistance
    :reader xDistance
    :initarg :xDistance
    :type cl:integer
    :initform 0)
   (yDistance
    :reader yDistance
    :initarg :yDistance
    :type cl:integer
    :initform 0)
   (distance
    :reader distance
    :initarg :distance
    :type cl:integer
    :initform 0))
)

(cl:defclass Distance (<Distance>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Distance>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Distance)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name software_training_assignment-msg:<Distance> is deprecated: use software_training_assignment-msg:Distance instead.")))

(cl:ensure-generic-function 'xDistance-val :lambda-list '(m))
(cl:defmethod xDistance-val ((m <Distance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader software_training_assignment-msg:xDistance-val is deprecated.  Use software_training_assignment-msg:xDistance instead.")
  (xDistance m))

(cl:ensure-generic-function 'yDistance-val :lambda-list '(m))
(cl:defmethod yDistance-val ((m <Distance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader software_training_assignment-msg:yDistance-val is deprecated.  Use software_training_assignment-msg:yDistance instead.")
  (yDistance m))

(cl:ensure-generic-function 'distance-val :lambda-list '(m))
(cl:defmethod distance-val ((m <Distance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader software_training_assignment-msg:distance-val is deprecated.  Use software_training_assignment-msg:distance instead.")
  (distance m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Distance>) ostream)
  "Serializes a message object of type '<Distance>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'xDistance)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'xDistance)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'xDistance)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'xDistance)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'yDistance)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'yDistance)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'yDistance)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'yDistance)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'distance)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'distance)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'distance)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'distance)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Distance>) istream)
  "Deserializes a message object of type '<Distance>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'xDistance)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'xDistance)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'xDistance)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'xDistance)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'yDistance)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'yDistance)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'yDistance)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'yDistance)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'distance)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'distance)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'distance)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'distance)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Distance>)))
  "Returns string type for a message object of type '<Distance>"
  "software_training_assignment/Distance")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Distance)))
  "Returns string type for a message object of type 'Distance"
  "software_training_assignment/Distance")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Distance>)))
  "Returns md5sum for a message object of type '<Distance>"
  "bd9e80af1a4aa422f1993f6c21a12fac")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Distance)))
  "Returns md5sum for a message object of type 'Distance"
  "bd9e80af1a4aa422f1993f6c21a12fac")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Distance>)))
  "Returns full string definition for message of type '<Distance>"
  (cl:format cl:nil "uint32 xDistance~%uint32 yDistance~%uint32 distance~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Distance)))
  "Returns full string definition for message of type 'Distance"
  (cl:format cl:nil "uint32 xDistance~%uint32 yDistance~%uint32 distance~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Distance>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Distance>))
  "Converts a ROS message object to a list"
  (cl:list 'Distance
    (cl:cons ':xDistance (xDistance msg))
    (cl:cons ':yDistance (yDistance msg))
    (cl:cons ':distance (distance msg))
))
