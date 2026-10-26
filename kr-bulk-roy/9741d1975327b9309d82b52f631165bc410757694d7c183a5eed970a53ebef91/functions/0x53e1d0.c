
void FUN_0053e1d0(void)

{
  int *piVar1;
  int unaff_EDI;
  
  piVar1 = *(int **)(unaff_EDI + 0x40);
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0089120c(*piVar1);
    }
    *piVar1 = 0;
    piVar1[1] = 0;
    piVar1[2] = 0;
    FUN_0089120c(piVar1);
    *(undefined4 *)(unaff_EDI + 0x40) = 0;
  }
  piVar1 = *(int **)(unaff_EDI + 0x44);
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0089120c(*piVar1);
    }
    *piVar1 = 0;
    piVar1[1] = 0;
    piVar1[2] = 0;
    FUN_0089120c(piVar1);
    *(undefined4 *)(unaff_EDI + 0x44) = 0;
  }
  return;
}

