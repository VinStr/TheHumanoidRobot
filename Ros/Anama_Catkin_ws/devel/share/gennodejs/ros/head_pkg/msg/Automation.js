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

class Automation {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.relay1 = null;
      this.relay2 = null;
      this.relay3 = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('relay1')) {
        this.relay1 = initObj.relay1
      }
      else {
        this.relay1 = false;
      }
      if (initObj.hasOwnProperty('relay2')) {
        this.relay2 = initObj.relay2
      }
      else {
        this.relay2 = false;
      }
      if (initObj.hasOwnProperty('relay3')) {
        this.relay3 = initObj.relay3
      }
      else {
        this.relay3 = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Automation
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [relay1]
    bufferOffset = _serializer.bool(obj.relay1, buffer, bufferOffset);
    // Serialize message field [relay2]
    bufferOffset = _serializer.bool(obj.relay2, buffer, bufferOffset);
    // Serialize message field [relay3]
    bufferOffset = _serializer.bool(obj.relay3, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Automation
    let len;
    let data = new Automation(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [relay1]
    data.relay1 = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [relay2]
    data.relay2 = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [relay3]
    data.relay3 = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 3;
  }

  static datatype() {
    // Returns string type for a message object
    return 'head_pkg/Automation';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'bb789613f23439dcb13bc2641016e45e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    bool relay1
    bool relay2
    bool relay3
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
    const resolved = new Automation(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.relay1 !== undefined) {
      resolved.relay1 = msg.relay1;
    }
    else {
      resolved.relay1 = false
    }

    if (msg.relay2 !== undefined) {
      resolved.relay2 = msg.relay2;
    }
    else {
      resolved.relay2 = false
    }

    if (msg.relay3 !== undefined) {
      resolved.relay3 = msg.relay3;
    }
    else {
      resolved.relay3 = false
    }

    return resolved;
    }
};

module.exports = Automation;
