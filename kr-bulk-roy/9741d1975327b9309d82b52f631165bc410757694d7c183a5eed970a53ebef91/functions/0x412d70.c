
int FUN_00412d70(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int unaff_EDI;
  
  *(undefined2 *)(unaff_EDI + 0x1c) = 0;
  iVar4 = in_ECX;
  uVar6 = 0xd;
  while( true ) {
    uVar5 = uVar6;
    iVar2 = iVar4 / 10;
    if (-1 < in_ECX) {
      sVar1 = (short)iVar4 + (short)iVar2 * -10;
    }
    else {
      sVar1 = (short)iVar2 * 10 - (short)iVar4;
    }
    *(short *)(unaff_EDI + uVar5 * 2) = sVar1 + 0x30;
    uVar6 = uVar5 - 1;
    if (iVar2 == 0) break;
    uVar3 = uVar6 & 0x80000003;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffffc) + 1;
    }
    iVar4 = iVar2;
    if (uVar3 == 2) {
      *(undefined2 *)(unaff_EDI + uVar6 * 2) = 0x2c;
      uVar6 = uVar5 - 2;
    }
  }
  if (-1 >= in_ECX) {
    *(undefined2 *)(unaff_EDI + uVar6 * 2) = 0x2d;
    return unaff_EDI + uVar6 * 2;
  }
  return unaff_EDI + 2 + uVar6 * 2;
}

