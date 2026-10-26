
void FUN_007a13e0(void)

{
  int *piVar1;
  int iVar2;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x10) != 0) {
    piVar1 = *(int **)(*(int *)(*(int *)(unaff_ESI + 4) + (*(uint *)(unaff_ESI + 0xc) >> 1) * 4) +
                       (*(uint *)(unaff_ESI + 0xc) & 1) * 8 + 4);
    if (piVar1 != (int *)0x0) {
      LOCK();
      iVar2 = piVar1[1] + -1;
      piVar1[1] = iVar2;
      UNLOCK();
      if (iVar2 == 0) {
        (**(code **)*piVar1)();
        LOCK();
        iVar2 = piVar1[2] + -1;
        piVar1[2] = iVar2;
        UNLOCK();
        if (iVar2 == 0) {
          (**(code **)(*piVar1 + 4))();
        }
      }
    }
    *(int *)(unaff_ESI + 0xc) = *(int *)(unaff_ESI + 0xc) + 1;
    if ((uint)(*(int *)(unaff_ESI + 8) * 2) <= *(uint *)(unaff_ESI + 0xc)) {
      *(undefined4 *)(unaff_ESI + 0xc) = 0;
    }
    piVar1 = (int *)(unaff_ESI + 0x10);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      *(undefined4 *)(unaff_ESI + 0xc) = 0;
    }
  }
  return;
}

