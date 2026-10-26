
int FUN_006abb80(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar2 = *(int *)(unaff_ESI + 0x14) - *(int *)(unaff_ESI + 0x10);
  iVar1 = iVar2 >> 0x1f;
  iVar2 = iVar2 / 0x33 + iVar1;
  uVar3 = 0;
  if (iVar2 != iVar1) {
    piVar4 = *(int **)(unaff_ESI + 0x10);
    do {
      if (*piVar4 == unaff_EDI) {
        return uVar3 + 1;
      }
      uVar3 = uVar3 + 1;
      piVar4 = (int *)((int)piVar4 + 0x33);
    } while (uVar3 < (uint)(iVar2 - iVar1));
  }
  return 0;
}

