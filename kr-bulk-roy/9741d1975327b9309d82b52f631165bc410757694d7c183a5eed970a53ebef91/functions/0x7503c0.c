
void FUN_007503c0(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_EDI == *(int **)(unaff_ESI + 0x13dc)) {
    *(undefined4 *)(unaff_ESI + 0x13dc) = 0;
  }
  if (unaff_EDI == *(int **)(unaff_ESI + 0x13d0)) {
    *(undefined4 *)(unaff_ESI + 0x13d0) = 0;
  }
  if (unaff_EDI == *(int **)(unaff_ESI + 0x13e4)) {
    *(undefined4 *)(unaff_ESI + 0x13e4) = 0;
  }
  if (unaff_EDI == *(int **)(unaff_ESI + 0x13cc)) {
    *(undefined4 *)(unaff_ESI + 0x13cc) = 0;
  }
  if (unaff_EDI == *(int **)(unaff_ESI + 0x13e0)) {
    *(undefined4 *)(unaff_ESI + 0x13e0) = 0;
  }
  if (unaff_EDI == *(int **)(unaff_ESI + 0x13e8)) {
    *(undefined4 *)(unaff_ESI + 0x13e8) = 0;
  }
  if (unaff_EDI == *(int **)(unaff_ESI + 0x13d4)) {
    *(undefined4 *)(unaff_ESI + 0x13d4) = 0;
  }
  if (unaff_EDI != (int *)0x0) {
    iVar2 = (**(code **)(*unaff_EDI + 0x58))();
    if (*(int *)(unaff_ESI + 0x13ec) == iVar2) {
      *(undefined4 *)(unaff_ESI + 0x13ec) = 0;
    }
    piVar1 = *(int **)(unaff_ESI + 0x13f0);
    piVar3 = (int *)(**(code **)(*unaff_EDI + 0x44))();
    if (piVar1 == piVar3) {
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0xd4))();
      }
      if (*(int **)(unaff_ESI + 0x13f0) != (int *)0x0) {
        (**(code **)(**(int **)(unaff_ESI + 0x13f0) + 0x130))();
      }
      *(undefined4 *)(unaff_ESI + 0x13f0) = 0;
    }
    if (*(int **)(unaff_ESI + 0x13c8) == unaff_EDI) {
      *(undefined4 *)(unaff_ESI + 0x13c8) = 0;
    }
  }
  return;
}

