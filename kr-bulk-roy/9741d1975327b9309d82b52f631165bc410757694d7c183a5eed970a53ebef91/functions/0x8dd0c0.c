
uint FUN_008dd0c0(void)

{
  uint uVar1;
  byte *in_ECX;
  byte *in_EDX;
  
  uVar1 = (uint)*in_ECX;
  if (uVar1 == 0x1c) {
    if (in_ECX + 3 <= in_EDX) {
      return (int)(short)((ushort)in_ECX[1] << 8) | (uint)in_ECX[2];
    }
  }
  else if (uVar1 == 0x1d) {
    if (in_ECX + 5 <= in_EDX) {
      return CONCAT31(CONCAT21(CONCAT11(in_ECX[1],in_ECX[2]),in_ECX[3]),in_ECX[4]);
    }
  }
  else {
    if (uVar1 < 0xf7) {
      return uVar1 - 0x8b;
    }
    if (uVar1 < 0xfb) {
      if (in_ECX + 2 <= in_EDX) {
        return uVar1 * 0x100 + -0xf694 + (uint)in_ECX[1];
      }
    }
    else if (in_ECX + 2 <= in_EDX) {
      return (uVar1 * -0x100 + 0xfa94) - (uint)in_ECX[1];
    }
  }
  return 0;
}

