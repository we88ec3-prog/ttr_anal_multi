
int FUN_008d1150(void)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  int *extraout_EDX;
  
  FUN_008d10e0();
  if (0 < extraout_EDX[3]) {
    return 0;
  }
  iVar2 = *extraout_EDX + -1;
  while (pbVar1 = (byte *)*extraout_EDX, pbVar1 < (byte *)extraout_EDX[2]) {
    uVar3 = (uint)*pbVar1;
    *extraout_EDX = (int)(pbVar1 + 1);
    if ((uVar3 == 0x20) || (uVar3 == 9)) {
      return iVar2;
    }
    if ((uVar3 == 0xd) || (uVar3 == 10)) {
      extraout_EDX[3] = 2;
      return iVar2;
    }
    if (uVar3 == 0x3b) {
      extraout_EDX[3] = 1;
      return iVar2;
    }
    if ((uVar3 == 0xffffffff) || (uVar3 == 0x1a)) break;
  }
  extraout_EDX[3] = 3;
  return iVar2;
}

