# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from head_pkg/Head.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import std_msgs.msg

class Head(genpy.Message):
  _md5sum = "802348f5a2f1e8dfd50efdc8d6faf838"
  _type = "head_pkg/Head"
  _has_header = True  # flag to mark the presence of a Header object
  _full_text = """Header header
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
"""
  __slots__ = ['header','eyesX','eyesY','jawX','jawY','eyeSkwint','jawZ','expression','blink','supprise','rightNose','leftNose']
  _slot_types = ['std_msgs/Header','int16','int16','int16','int16','int16','int16','int16','bool','bool','bool','bool']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       header,eyesX,eyesY,jawX,jawY,eyeSkwint,jawZ,expression,blink,supprise,rightNose,leftNose

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(Head, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.eyesX is None:
        self.eyesX = 0
      if self.eyesY is None:
        self.eyesY = 0
      if self.jawX is None:
        self.jawX = 0
      if self.jawY is None:
        self.jawY = 0
      if self.eyeSkwint is None:
        self.eyeSkwint = 0
      if self.jawZ is None:
        self.jawZ = 0
      if self.expression is None:
        self.expression = 0
      if self.blink is None:
        self.blink = False
      if self.supprise is None:
        self.supprise = False
      if self.rightNose is None:
        self.rightNose = False
      if self.leftNose is None:
        self.leftNose = False
    else:
      self.header = std_msgs.msg.Header()
      self.eyesX = 0
      self.eyesY = 0
      self.jawX = 0
      self.jawY = 0
      self.eyeSkwint = 0
      self.jawZ = 0
      self.expression = 0
      self.blink = False
      self.supprise = False
      self.rightNose = False
      self.leftNose = False

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_7h4B().pack(_x.eyesX, _x.eyesY, _x.jawX, _x.jawY, _x.eyeSkwint, _x.jawZ, _x.expression, _x.blink, _x.supprise, _x.rightNose, _x.leftNose))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 18
      (_x.eyesX, _x.eyesY, _x.jawX, _x.jawY, _x.eyeSkwint, _x.jawZ, _x.expression, _x.blink, _x.supprise, _x.rightNose, _x.leftNose,) = _get_struct_7h4B().unpack(str[start:end])
      self.blink = bool(self.blink)
      self.supprise = bool(self.supprise)
      self.rightNose = bool(self.rightNose)
      self.leftNose = bool(self.leftNose)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_7h4B().pack(_x.eyesX, _x.eyesY, _x.jawX, _x.jawY, _x.eyeSkwint, _x.jawZ, _x.expression, _x.blink, _x.supprise, _x.rightNose, _x.leftNose))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 18
      (_x.eyesX, _x.eyesY, _x.jawX, _x.jawY, _x.eyeSkwint, _x.jawZ, _x.expression, _x.blink, _x.supprise, _x.rightNose, _x.leftNose,) = _get_struct_7h4B().unpack(str[start:end])
      self.blink = bool(self.blink)
      self.supprise = bool(self.supprise)
      self.rightNose = bool(self.rightNose)
      self.leftNose = bool(self.leftNose)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_3I = None
def _get_struct_3I():
    global _struct_3I
    if _struct_3I is None:
        _struct_3I = struct.Struct("<3I")
    return _struct_3I
_struct_7h4B = None
def _get_struct_7h4B():
    global _struct_7h4B
    if _struct_7h4B is None:
        _struct_7h4B = struct.Struct("<7h4B")
    return _struct_7h4B
