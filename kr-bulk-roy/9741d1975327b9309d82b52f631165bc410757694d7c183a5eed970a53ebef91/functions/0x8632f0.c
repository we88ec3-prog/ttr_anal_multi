
void FUN_008632f0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  int unaff_ESI;
  
  iVar4 = *(int *)(unaff_ESI + 0x10);
  while (iVar4 != 0) {
    if (*(int *)(unaff_ESI + 0x10) != 0) {
      uVar3 = *(int *)(unaff_ESI + 0x10) + -1 + *(int *)(unaff_ESI + 0xc);
      if (*(uint *)(unaff_ESI + 8) <= uVar3) {
        uVar3 = uVar3 - *(uint *)(unaff_ESI + 8);
      }
      puVar2 = *(undefined4 **)(*(int *)(unaff_ESI + 4) + uVar3 * 4);
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      puVar2[4] = 0;
      puVar2[5] = 0;
      puVar2[6] = 0xffffffff;
      puVar2[7] = 0;
      puVar2[8] = 0;
      piVar1 = (int *)(unaff_ESI + 0x10);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        *(undefined4 *)(unaff_ESI + 0xc) = 0;
      }
    }
    iVar4 = *(int *)(unaff_ESI + 0x10);
  }
  iVar4 = *(int *)(unaff_ESI + 8);
  while (iVar4 != 0) {
    iVar4 = iVar4 + -1;
    if (*(int *)(*(int *)(unaff_ESI + 4) + iVar4 * 4) != 0) {
      FUN_0089120c(*(undefined4 *)(*(int *)(unaff_ESI + 4) + iVar4 * 4));
    }
  }
  if (*(int *)(unaff_ESI + 4) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 4));
  }
  *(undefined4 *)(unaff_ESI + 4) = 0;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  return;
}

