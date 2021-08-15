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

class Neck {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.NeckTurnPos = null;
      this.HeadPitch = null;
      this.HeadRoll = null;
      this.SensPitch = null;
      this.SensRoll = null;
      this.ToungeExpression = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('NeckTurnPos')) {
        this.NeckTurnPos = initObj.NeckTurnPos
      }
      else {
        this.NeckTurnPos = 0;
      }
      if (initObj.hasOwnProperty('HeadPitch')) {
        this.HeadPitch = initObj.HeadPitch
      }
      else {
        this.HeadPitch = 0;
      }
      if (initObj.hasOwnProperty('HeadRoll')) {
        this.HeadRoll = initObj.HeadRoll
      }
      else {
        this.HeadRoll = 0;
      }
      if (initObj.hasOwnProperty('SensPitch')) {
        this.SensPitch = initObj.SensPitch
      }
      else {
        this.SensPitch = 0.0;
      }
      if (initObj.hasOwnProperty('SensRoll')) {
        this.SensRoll = initObj.SensRoll
      }
      else {
        this.SensRoll = 0.0;
      }
      if (initObj.hasOwnProperty('ToungeExpression')) {
        this.ToungeExpression = initObj.ToungeExpression
      }
      else {
        this.ToungeExpression = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Neck
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [NeckTurnPos]
    bufferOffset = _serializer.int16(obj.NeckTurnPos, buffer, bufferOffset);
    // Serialize message field [HeadPitch]
    bufferOffset = _serializer.int16(obj.HeadPitch, buffer, bufferOffset);
    // Serialize message field [HeadRoll]
    bufferOffset = _serializer.int16(obj.HeadRoll, buffer, bufferOffset);
    // Serialize message field [SensPitch]
    bufferOffset = _serializer.float32(obj.SensPitch, buffer, bufferOffset);
    // Serialize message field [SensRoll]
    bufferOffset = _serializer.float32(obj.SensRoll, buffer, bufferOffset);
    // Serialize message field [ToungeExpression]
    bufferOffset = _serializer.int16(obj.ToungeExpression, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Neck
    let len;
    let data = new Neck(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [NeckTurnPos]
    data.NeckTurnPos = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [HeadPitch]
    data.HeadPitch = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [HeadRoll]
    data.HeadRoll = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [SensPitch]
    data.SensPitch = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [SensRoll]
    data.SensRoll = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [ToungeExpression]
    data.ToungeExpression = _deserializer.int16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'head_pkg/Neck';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ee86276cb042e4ad198a659440dd1e51';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    int16 NeckTurnPos
    int16 HeadPitch
    int16 HeadRoll
    float32 SensPitch
    float32 SensRoll
    int16 ToungeExpression
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
    const resolved = new Neck(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.NeckTurnPos !== undefined) {
      resolved.NeckTurnPos = msg.NeckTurnPos;
    }
    else {
      resolved.NeckTurnPos = 0
    }

    if (msg.HeadPitch !== undefined) {
      resolved.HeadPitch = msg.HeadPitch;
    }
    else {
      resolved.HeadPitch = 0
    }

    if (msg.HeadRoll !== undefined) {
      resolved.HeadRoll = msg.HeadRoll;
    }
    else {
      resolved.HeadRoll = 0
    }

    if (msg.SensPitch !== undefined) {
      resolved.SensPitch = msg.SensPitch;
    }
    else {
      resolved.SensPitch = 0.0
    }

    if (msg.SensRoll !== undefined) {
      resolved.SensRoll = msg.SensRoll;
    }
    else {
      resolved.SensRoll = 0.0
    }

    if (msg.ToungeExpression !== undefined) {
      resolved.ToungeExpression = msg.ToungeExpression;
    }
    else {
      resolved.ToungeExpression = 0
    }

    return resolved;
    }
};

module.exports = Neck;
