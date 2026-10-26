
int FUN_008d11c0(void)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  int *extraout_EDX;
  
  FUN_008d10e0();
  if (1 < extraout_EDX[3]) {
    return 0;
  }
  iVar1 = *extraout_EDX;
  while (pbVar2 = (byte *)*extraout_EDX, pbVar2 < (byte *)extraout_EDX[2]) {
    uVar3 = (uint)*pbVar2;
    *extraout_EDX = (int)(pbVar2 + 1);
    if ((uVar3 == 0xd) || (uVar3 == 10)) {
      extraout_EDX[3] = 2;
      return iVar1 + -1;
    }
    if ((uVar3 == 0xffffffff) || (uVar3 == 0x1a)) break;
  }
  extraout_EDX[3] = 3;
  return iVar1 + -1;
}

