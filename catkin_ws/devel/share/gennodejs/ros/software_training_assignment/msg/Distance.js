// Auto-generated. Do not edit!

// (in-package software_training_assignment.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Distance {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.xDistance = null;
      this.yDistance = null;
      this.distance = null;
    }
    else {
      if (initObj.hasOwnProperty('xDistance')) {
        this.xDistance = initObj.xDistance
      }
      else {
        this.xDistance = 0;
      }
      if (initObj.hasOwnProperty('yDistance')) {
        this.yDistance = initObj.yDistance
      }
      else {
        this.yDistance = 0;
      }
      if (initObj.hasOwnProperty('distance')) {
        this.distance = initObj.distance
      }
      else {
        this.distance = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Distance
    // Serialize message field [xDistance]
    bufferOffset = _serializer.uint32(obj.xDistance, buffer, bufferOffset);
    // Serialize message field [yDistance]
    bufferOffset = _serializer.uint32(obj.yDistance, buffer, bufferOffset);
    // Serialize message field [distance]
    bufferOffset = _serializer.uint32(obj.distance, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Distance
    let len;
    let data = new Distance(null);
    // Deserialize message field [xDistance]
    data.xDistance = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [yDistance]
    data.yDistance = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [distance]
    data.distance = _deserializer.uint32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'software_training_assignment/Distance';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'bd9e80af1a4aa422f1993f6c21a12fac';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint32 xDistance
    uint32 yDistance
    uint32 distance
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Distance(null);
    if (msg.xDistance !== undefined) {
      resolved.xDistance = msg.xDistance;
    }
    else {
      resolved.xDistance = 0
    }

    if (msg.yDistance !== undefined) {
      resolved.yDistance = msg.yDistance;
    }
    else {
      resolved.yDistance = 0
    }

    if (msg.distance !== undefined) {
      resolved.distance = msg.distance;
    }
    else {
      resolved.distance = 0
    }

    return resolved;
    }
};

module.exports = Distance;
