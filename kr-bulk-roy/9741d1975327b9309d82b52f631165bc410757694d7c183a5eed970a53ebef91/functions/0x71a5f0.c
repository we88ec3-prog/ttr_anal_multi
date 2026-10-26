
byte * FUN_0071a5f0(void)

{
  byte bVar1;
  uint in_EAX;
  byte *in_ECX;
  
  bVar1 = (byte)in_EAX;
  if (in_EAX < 0x80) {
    *in_ECX = bVar1;
    return in_ECX + 1;
  }
  if (in_EAX < 0x800) {
    in_ECX[1] = bVar1 & 0x3f | 0x80;
    *in_ECX = (byte)(in_EAX >> 6) | 0xc0;
    return in_ECX + 2;
  }
  *in_ECX = (byte)(in_EAX >> 0xc) | 0xe0;
  in_ECX[2] = bVar1 & 0x3f | 0x80;
  in_ECX[1] = (byte)(in_EAX >> 6) & 0x3f | 0x80;
  return in_ECX + 3;
}

