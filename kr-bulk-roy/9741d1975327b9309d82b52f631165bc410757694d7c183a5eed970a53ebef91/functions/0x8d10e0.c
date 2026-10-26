
uint FUN_008d10e0(void)

{
  byte *pbVar1;
  uint uVar2;
  undefined4 *in_EDX;
  
  if (0 < (int)in_EDX[3]) {
    return 0x3b;
  }
  do {
    pbVar1 = (byte *)*in_EDX;
    if ((byte *)in_EDX[2] <= pbVar1) {
      in_EDX[3] = 3;
      return 0xffffffff;
    }
    uVar2 = (uint)*pbVar1;
    *in_EDX = pbVar1 + 1;
  } while ((uVar2 == 0x20) || (uVar2 == 9));
  if ((uVar2 == 0xd) || (uVar2 == 10)) {
    in_EDX[3] = 2;
  }
  else {
    if (uVar2 == 0x3b) {
      in_EDX[3] = 1;
      return 0x3b;
    }
    if ((uVar2 == 0xffffffff) || (uVar2 == 0x1a)) {
      in_EDX[3] = 3;
      return uVar2;
    }
  }
  return uVar2;
}

