
byte * FUN_0071a640(void)

{
  uint in_EAX;
  byte *pbVar1;
  byte *in_ECX;
  
  if (in_EAX < 0x10000) {
    pbVar1 = (byte *)FUN_0071a5f0();
    return pbVar1;
  }
  *in_ECX = (byte)(in_EAX >> 0x12) | 0xf0;
  in_ECX[1] = (byte)(in_EAX >> 0xc) & 0x3f | 0x80;
  in_ECX[3] = (byte)in_EAX & 0x3f | 0x80;
  in_ECX[2] = (byte)(in_EAX >> 6) & 0x3f | 0x80;
  return in_ECX + 4;
}

