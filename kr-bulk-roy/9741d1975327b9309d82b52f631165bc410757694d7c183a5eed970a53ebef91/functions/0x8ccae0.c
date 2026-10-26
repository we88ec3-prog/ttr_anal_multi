
void FUN_008ccae0(void)

{
  byte *pbVar1;
  uint in_ECX;
  uint *in_EDX;
  
  if (in_ECX < *in_EDX) {
    pbVar1 = (byte *)(((int)in_ECX >> 3) + in_EDX[2]);
    *pbVar1 = *pbVar1 & ~(byte)(0x80 >> ((byte)in_ECX & 7));
  }
  return;
}

