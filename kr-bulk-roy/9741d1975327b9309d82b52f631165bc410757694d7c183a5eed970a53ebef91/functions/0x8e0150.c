
int FUN_008e0150(int param_1)

{
  uint in_EAX;
  
  if (param_1 == 1) {
    return 0;
  }
  if (in_EAX < 0x4d8) {
    return 0x6b;
  }
  return (-(uint)(in_EAX < 0x846c) & 0xffff846b) + 0x8000;
}

