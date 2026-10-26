
char FUN_004c6f60(void)

{
  byte bVar1;
  uint in_ECX;
  byte *in_EDX;
  
  if (*in_EDX == in_ECX) {
    return '\x10';
  }
  if (in_ECX < 8) {
    bVar1 = (byte)(1 << ((byte)in_ECX & 0x1f));
    if ((in_EDX[1] & bVar1) != 0) {
      return (-((in_EDX[2] & bVar1) != 0) & 0x6eU) + 0x11;
    }
    if ((in_EDX[2] & bVar1) != 0) {
      return '\x12';
    }
  }
  return '\x7f';
}

