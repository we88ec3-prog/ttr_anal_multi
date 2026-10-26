
void FUN_004c4240(void)

{
  int *piVar1;
  uint uVar2;
  int unaff_ESI;
  int iVar3;
  
  iVar3 = *(int *)(unaff_ESI + 0x10);
  while (iVar3 != 0) {
    if (*(int *)(unaff_ESI + 0x10) != 0) {
      uVar2 = *(int *)(unaff_ESI + 0x10) + -1 + *(int *)(unaff_ESI + 0xc);
      if (*(uint *)(unaff_ESI + 8) <= uVar2) {
        uVar2 = uVar2 - *(uint *)(unaff_ESI + 8);
      }
      iVar3 = *(int *)(*(int *)(unaff_ESI + 4) + uVar2 * 4);
      if (*(int *)(iVar3 + 0x40) != 0) {
        FUN_0089120c(*(int *)(iVar3 + 0x40));
      }
      *(undefined4 *)(iVar3 + 0x40) = 0;
      *(undefined4 *)(iVar3 + 0x44) = 0;
      *(undefined4 *)(iVar3 + 0x48) = 0;
      piVar1 = (int *)(unaff_ESI + 0x10);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        *(undefined4 *)(unaff_ESI + 0xc) = 0;
      }
    }
    iVar3 = *(int *)(unaff_ESI + 0x10);
  }
  iVar3 = *(int *)(unaff_ESI + 8);
  while (iVar3 != 0) {
    iVar3 = iVar3 + -1;
    if (*(int *)(*(int *)(unaff_ESI + 4) + iVar3 * 4) != 0) {
      FUN_0089120c(*(undefined4 *)(*(int *)(unaff_ESI + 4) + iVar3 * 4));
    }
  }
  if (*(int *)(unaff_ESI + 4) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 4));
  }
  *(undefined4 *)(unaff_ESI + 4) = 0;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  return;
}

