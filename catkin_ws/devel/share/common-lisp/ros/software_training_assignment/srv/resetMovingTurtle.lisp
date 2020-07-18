; Auto-generated. Do not edit!


(cl:in-package software_training_assignment-srv)


;//! \htmlinclude resetMovingTurtle-request.msg.html

(cl:defclass <resetMovingTurtle-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass resetMovingTurtle-request (<resetMovingTurtle-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <resetMovingTurtle-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'resetMovingTurtle-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name software_training_assignment-srv:<resetMovingTurtle-request> is deprecated: use software_training_assignment-srv:resetMovingTurtle-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <resetMovingTurtle-request>) ostream)
  "Serializes a message object of type '<resetMovingTurtle-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <resetMovingTurtle-request>) istream)
  "Deserializes a message object of type '<resetMovingTurtle-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<resetMovingTurtle-request>)))
  "Returns string type for a service object of type '<resetMovingTurtle-request>"
  "software_training_assignment/resetMovingTurtleRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'resetMovingTurtle-request)))
  "Returns string type for a service object of type 'resetMovingTurtle-request"
  "software_training_assignment/resetMovingTurtleRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<resetMovingTurtle-request>)))
  "Returns md5sum for a message object of type '<resetMovingTurtle-request>"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'resetMovingTurtle-request)))
  "Returns md5sum for a message object of type 'resetMovingTurtle-request"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<resetMovingTurtle-request>)))
  "Returns full string definition for message of type '<resetMovingTurtle-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'resetMovingTurtle-request)))
  "Returns full string definition for message of type 'resetMovingTurtle-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <resetMovingTurtle-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <resetMovingTurtle-request>))
  "Converts a ROS message object to a list"
  (cl:list 'resetMovingTurtle-request
))
;//! \htmlinclude resetMovingTurtle-response.msg.html

(cl:defclass <resetMovingTurtle-response> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass resetMovingTurtle-response (<resetMovingTurtle-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <resetMovingTurtle-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'resetMovingTurtle-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name software_training_assignment-srv:<resetMovingTurtle-response> is deprecated: use software_training_assignment-srv:resetMovingTurtle-response instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <resetMovingTurtle-response>) ostream)
  "Serializes a message object of type '<resetMovingTurtle-response>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <resetMovingTurtle-response>) istream)
  "Deserializes a message object of type '<resetMovingTurtle-response>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<resetMovingTurtle-response>)))
  "Returns string type for a service object of type '<resetMovingTurtle-response>"
  "software_training_assignment/resetMovingTurtleResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'resetMovingTurtle-response)))
  "Returns string type for a service object of type 'resetMovingTurtle-response"
  "software_training_assignment/resetMovingTurtleResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<resetMovingTurtle-response>)))
  "Returns md5sum for a message object of type '<resetMovingTurtle-response>"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'resetMovingTurtle-response)))
  "Returns md5sum for a message object of type 'resetMovingTurtle-response"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<resetMovingTurtle-response>)))
  "Returns full string definition for message of type '<resetMovingTurtle-response>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'resetMovingTurtle-response)))
  "Returns full string definition for message of type 'resetMovingTurtle-response"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <resetMovingTurtle-response>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <resetMovingTurtle-response>))
  "Converts a ROS message object to a list"
  (cl:list 'resetMovingTurtle-response
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'resetMovingTurtle)))
  'resetMovingTurtle-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'resetMovingTurtle)))
  'resetMovingTurtle-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'resetMovingTurtle)))
  "Returns string type for a service object of type '<resetMovingTurtle>"
  "software_training_assignment/resetMovingTurtle")