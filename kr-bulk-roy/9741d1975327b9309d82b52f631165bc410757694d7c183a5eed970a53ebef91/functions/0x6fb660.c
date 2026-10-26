
void FUN_006fb660(uint param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int unaff_ESI;
  
  bVar1 = *(byte *)(unaff_ESI + 0x38);
  uVar2 = *(uint *)(unaff_ESI + 0x18);
  *(uint *)(unaff_ESI + 0x18) = param_1;
  if (((bVar1 & 8) != 0) && (*(int *)(unaff_ESI + 0x40) == 0)) {
    *(undefined4 *)(unaff_ESI + 0x40) = *(undefined4 *)(unaff_ESI + 0x3c);
    FUN_006fdde0(0xffffffff);
  }
  if ((bVar1 & 4) != 0) {
    iVar5 = *(int *)(**(int **)(*(int *)(unaff_ESI + 0x14) + 4) + 0x10);
    iVar3 = *(int *)(iVar5 + 0xc);
    iVar5 = *(int *)(iVar5 + 0x14);
    iVar4 = ((int)(param_1 - iVar3) >> 2) + -1;
    if (iVar5 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(iVar5 + iVar4 * 4);
    }
    if ((iVar4 != 0) && (uVar2 < param_1)) {
      if (iVar5 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(iVar5 + -4 + ((int)(uVar2 - iVar3) >> 2) * 4);
      }
      if (iVar6 == iVar5) {
        return;
      }
    }
    FUN_006fdde0(iVar6);
  }
  return;
}

