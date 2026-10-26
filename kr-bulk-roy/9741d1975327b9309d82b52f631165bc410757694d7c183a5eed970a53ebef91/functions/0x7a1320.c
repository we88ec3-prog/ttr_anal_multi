
void FUN_007a1320(void)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  int unaff_ESI;
  int iVar4;
  
  iVar4 = *(int *)(unaff_ESI + 0x10);
  while (iVar4 != 0) {
    if (*(int *)(unaff_ESI + 0x10) != 0) {
      uVar1 = *(int *)(unaff_ESI + 0x10) + -1 + *(int *)(unaff_ESI + 0xc);
      uVar3 = uVar1 >> 1;
      if (*(uint *)(unaff_ESI + 8) <= uVar3) {
        uVar3 = uVar3 - *(uint *)(unaff_ESI + 8);
      }
      piVar2 = *(int **)(*(int *)(*(int *)(unaff_ESI + 4) + uVar3 * 4) + 4 + (uVar1 & 1) * 8);
      if (piVar2 != (int *)0x0) {
        LOCK();
        iVar4 = piVar2[1] + -1;
        piVar2[1] = iVar4;
        UNLOCK();
        if (iVar4 == 0) {
          (**(code **)*piVar2)();
          LOCK();
          iVar4 = piVar2[2] + -1;
          piVar2[2] = iVar4;
          UNLOCK();
          if (iVar4 == 0) {
            (**(code **)(*piVar2 + 4))();
          }
        }
      }
      piVar2 = (int *)(unaff_ESI + 0x10);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 == 0) {
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

