; Auto-generated. Do not edit!


(cl:in-package software_training_assignment-msg)


;//! \htmlinclude MoveFeedback.msg.html

(cl:defclass <MoveFeedback> (roslisp-msg-protocol:ros-message)
  ((distance
    :reader distance
    :initarg :distance
    :type cl:float
    :initform 0.0))
)

(cl:defclass MoveFeedback (<MoveFeedback>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MoveFeedback>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MoveFeedback)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name software_training_assignment-msg:<MoveFeedback> is deprecated: use software_training_assignment-msg:MoveFeedback instead.")))

(cl:ensure-generic-function 'distance-val :lambda-list '(m))
(cl:defmethod distance-val ((m <MoveFeedback>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader software_training_assignment-msg:distance-val is deprecated.  Use software_training_assignment-msg:distance instead.")
  (distance m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MoveFeedback>) ostream)
  "Serializes a message object of type '<MoveFeedback>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'distance))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MoveFeedback>) istream)
  "Deserializes a message object of type '<MoveFeedback>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'distance) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MoveFeedback>)))
  "Returns string type for a message object of type '<MoveFeedback>"
  "software_training_assignment/MoveFeedback")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MoveFeedback)))
  "Returns string type for a message object of type 'MoveFeedback"
  "software_training_assignment/MoveFeedback")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MoveFeedback>)))
  "Returns md5sum for a message object of type '<MoveFeedback>"
  "6e77fb10f0c8b4833ec273aa9ac74459")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MoveFeedback)))
  "Returns md5sum for a message object of type 'MoveFeedback"
  "6e77fb10f0c8b4833ec273aa9ac74459")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MoveFeedback>)))
  "Returns full string definition for message of type '<MoveFeedback>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#feedback~%float32 distance~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MoveFeedback)))
  "Returns full string definition for message of type 'MoveFeedback"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#feedback~%float32 distance~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MoveFeedback>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MoveFeedback>))
  "Converts a ROS message object to a list"
  (cl:list 'MoveFeedback
    (cl:cons ':distance (distance msg))
))
