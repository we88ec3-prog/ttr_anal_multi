
char FUN_0073fcb0(void)

{
  byte in_AL;
  
  if (0xc0 < in_AL) {
    return (in_AL >> 1) + 0x80;
  }
  if (0x60 < in_AL) {
    return (char)((ulonglong)((longlong)(int)((uint)in_AL * 2) * 0x55555556) >> 0x20) + '`';
  }
  if (0x20 < in_AL) {
    return in_AL + 0x40;
  }
  if (0x13 < in_AL) {
    return (char)(((uint)in_AL * 3) / 2) + '0';
  }
  return in_AL * '\x04';
}

