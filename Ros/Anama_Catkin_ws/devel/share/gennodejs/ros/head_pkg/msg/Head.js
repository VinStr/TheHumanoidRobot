// Auto-generated. Do not edit!

// (in-package head_pkg.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class Head {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.eyesX = null;
      this.eyesY = null;
      this.jawX = null;
      this.jawY = null;
      this.eyeSkwint = null;
      this.jawZ = null;
      this.expression = null;
      this.blink = null;
      this.supprise = null;
      this.rightNose = null;
      this.leftNose = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('eyesX')) {
        this.eyesX = initObj.eyesX
      }
      else {
        this.eyesX = 0;
      }
      if (initObj.hasOwnProperty('eyesY')) {
        this.eyesY = initObj.eyesY
      }
      else {
        this.eyesY = 0;
      }
      if (initObj.hasOwnProperty('jawX')) {
        this.jawX = initObj.jawX
      }
      else {
        this.jawX = 0;
      }
      if (initObj.hasOwnProperty('jawY')) {
        this.jawY = initObj.jawY
      }
      else {
        this.jawY = 0;
      }
      if (initObj.hasOwnProperty('eyeSkwint')) {
        this.eyeSkwint = initObj.eyeSkwint
      }
      else {
        this.eyeSkwint = 0;
      }
      if (initObj.hasOwnProperty('jawZ')) {
        this.jawZ = initObj.jawZ
      }
      else {
        this.jawZ = 0;
      }
      if (initObj.hasOwnProperty('expression')) {
        this.expression = initObj.expression
      }
      else {
        this.expression = 0;
      }
      if (initObj.hasOwnProperty('blink')) {
        this.blink = initObj.blink
      }
      else {
        this.blink = false;
      }
      if (initObj.hasOwnProperty('supprise')) {
        this.supprise = initObj.supprise
      }
      else {
        this.supprise = false;
      }
      if (initObj.hasOwnProperty('rightNose')) {
        this.rightNose = initObj.rightNose
      }
      else {
        this.rightNose = false;
      }
      if (initObj.hasOwnProperty('leftNose')) {
        this.leftNose = initObj.leftNose
      }
      else {
        this.leftNose = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Head
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [eyesX]
    bufferOffset = _serializer.int16(obj.eyesX, buffer, bufferOffset);
    // Serialize message field [eyesY]
    bufferOffset = _serializer.int16(obj.eyesY, buffer, bufferOffset);
    // Serialize message field [jawX]
    bufferOffset = _serializer.int16(obj.jawX, buffer, bufferOffset);
    // Serialize message field [jawY]
    bufferOffset = _serializer.int16(obj.jawY, buffer, bufferOffset);
    // Serialize message field [eyeSkwint]
    bufferOffset = _serializer.int16(obj.eyeSkwint, buffer, bufferOffset);
    // Serialize message field [jawZ]
    bufferOffset = _serializer.int16(obj.jawZ, buffer, bufferOffset);
    // Serialize message field [expression]
    bufferOffset = _serializer.int16(obj.expression, buffer, bufferOffset);
    // Serialize message field [blink]
    bufferOffset = _serializer.bool(obj.blink, buffer, bufferOffset);
    // Serialize message field [supprise]
    bufferOffset = _serializer.bool(obj.supprise, buffer, bufferOffset);
    // Serialize message field [rightNose]
    bufferOffset = _serializer.bool(obj.rightNose, buffer, bufferOffset);
    // Serialize message field [leftNose]
    bufferOffset = _serializer.bool(obj.leftNose, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Head
    let len;
    let data = new Head(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [eyesX]
    data.eyesX = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [eyesY]
    data.eyesY = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [jawX]
    data.jawX = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [jawY]
    data.jawY = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [eyeSkwint]
    data.eyeSkwint = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [jawZ]
    data.jawZ = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [expression]
    data.expression = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [blink]
    data.blink = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [supprise]
    data.supprise = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [rightNose]
    data.rightNose = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [leftNose]
    data.leftNose = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 18;
  }

  static datatype() {
    // Returns string type for a message object
    return 'head_pkg/Head';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '802348f5a2f1e8dfd50efdc8d6faf838';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    int16 eyesX
    int16 eyesY
    int16 jawX
    int16 jawY
    int16 eyeSkwint
    int16 jawZ
    int16 expression
    bool blink
    bool supprise
    bool rightNose
    bool leftNose
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Head(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.eyesX !== undefined) {
      resolved.eyesX = msg.eyesX;
    }
    else {
      resolved.eyesX = 0
    }

    if (msg.eyesY !== undefined) {
      resolved.eyesY = msg.eyesY;
    }
    else {
      resolved.eyesY = 0
    }

    if (msg.jawX !== undefined) {
      resolved.jawX = msg.jawX;
    }
    else {
      resolved.jawX = 0
    }

    if (msg.jawY !== undefined) {
      resolved.jawY = msg.jawY;
    }
    else {
      resolved.jawY = 0
    }

    if (msg.eyeSkwint !== undefined) {
      resolved.eyeSkwint = msg.eyeSkwint;
    }
    else {
      resolved.eyeSkwint = 0
    }

    if (msg.jawZ !== undefined) {
      resolved.jawZ = msg.jawZ;
    }
    else {
      resolved.jawZ = 0
    }

    if (msg.expression !== undefined) {
      resolved.expression = msg.expression;
    }
    else {
      resolved.expression = 0
    }

    if (msg.blink !== undefined) {
      resolved.blink = msg.blink;
    }
    else {
      resolved.blink = false
    }

    if (msg.supprise !== undefined) {
      resolved.supprise = msg.supprise;
    }
    else {
      resolved.supprise = false
    }

    if (msg.rightNose !== undefined) {
      resolved.rightNose = msg.rightNose;
    }
    else {
      resolved.rightNose = false
    }

    if (msg.leftNose !== undefined) {
      resolved.leftNose = msg.leftNose;
    }
    else {
      resolved.leftNose = false
    }

    return resolved;
    }
};

module.exports = Head;
