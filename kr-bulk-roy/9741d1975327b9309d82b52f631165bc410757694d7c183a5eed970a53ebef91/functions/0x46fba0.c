
void FUN_0046fba0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  int unaff_ESI;
  int iVar4;
  
  iVar4 = *(int *)(unaff_ESI + 0x10);
  while (iVar4 != 0) {
    if (*(int *)(unaff_ESI + 0x10) != 0) {
      uVar3 = *(int *)(unaff_ESI + 0x10) + -1 + *(int *)(unaff_ESI + 0xc);
      if (*(uint *)(unaff_ESI + 8) <= uVar3) {
        uVar3 = uVar3 - *(uint *)(unaff_ESI + 8);
      }
      puVar2 = *(undefined4 **)(*(int *)(unaff_ESI + 4) + uVar3 * 4);
      if (7 < (uint)puVar2[5]) {
        FUN_0089120c(*puVar2);
      }
      puVar2[5] = 7;
      puVar2[4] = 0;
      *(undefined2 *)puVar2 = 0;
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

