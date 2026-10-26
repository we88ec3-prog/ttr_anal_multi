
void FUN_00837ab0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int unaff_EDI;
  
  piVar1 = *(int **)(unaff_EDI + 0x24);
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0089120c(*piVar1);
    }
    *piVar1 = 0;
    piVar1[1] = 0;
    piVar1[2] = 0;
    FUN_0089120c(piVar1);
    *(undefined4 *)(unaff_EDI + 0x24) = 0;
  }
  if (*(int *)(unaff_EDI + 0x38) != 0) {
    FUN_0089120c(*(int *)(unaff_EDI + 0x38));
  }
  *(undefined4 *)(unaff_EDI + 0x38) = 0;
  *(undefined4 *)(unaff_EDI + 0x3c) = 0;
  *(undefined4 *)(unaff_EDI + 0x40) = 0;
  if (*(int *)(unaff_EDI + 0x28) != 0) {
    FUN_0089120c(*(int *)(unaff_EDI + 0x28));
  }
  *(undefined4 *)(unaff_EDI + 0x28) = 0;
  *(undefined4 *)(unaff_EDI + 0x2c) = 0;
  *(undefined4 *)(unaff_EDI + 0x30) = 0;
  iVar3 = *(int *)(unaff_EDI + 0x14);
  if (iVar3 != 0) {
    iVar2 = *(int *)(unaff_EDI + 0x18);
    for (; iVar3 != iVar2; iVar3 = iVar3 + 100) {
      FUN_00832c50();
    }
    FUN_0089120c(*(undefined4 *)(unaff_EDI + 0x14));
  }
  *(undefined4 *)(unaff_EDI + 0x14) = 0;
  *(undefined4 *)(unaff_EDI + 0x18) = 0;
  *(undefined4 *)(unaff_EDI + 0x1c) = 0;
  if (*(int *)(unaff_EDI + 4) != 0) {
    FUN_0089120c(*(int *)(unaff_EDI + 4));
  }
  *(undefined4 *)(unaff_EDI + 4) = 0;
  *(undefined4 *)(unaff_EDI + 8) = 0;
  *(undefined4 *)(unaff_EDI + 0xc) = 0;
  return;
}

