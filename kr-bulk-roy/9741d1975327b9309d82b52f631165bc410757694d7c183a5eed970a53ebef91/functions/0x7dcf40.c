
void FUN_007dcf40(void)

{
  int *piVar1;
  int unaff_EDI;
  
  piVar1 = *(int **)(unaff_EDI + 0x4c);
  if (piVar1 != *(int **)(unaff_EDI + 0x50)) {
    do {
      if (*piVar1 != 0) {
        FUN_0089120c(*piVar1);
        *piVar1 = 0;
      }
      piVar1 = piVar1 + 1;
    } while (piVar1 != *(int **)(unaff_EDI + 0x50));
  }
  if (*(int *)(unaff_EDI + 0x7c) != 0) {
    FUN_0089120c(*(int *)(unaff_EDI + 0x7c));
  }
  *(undefined4 *)(unaff_EDI + 0x7c) = 0;
  *(undefined4 *)(unaff_EDI + 0x80) = 0;
  *(undefined4 *)(unaff_EDI + 0x84) = 0;
  DeleteCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 100));
  if (*(int *)(unaff_EDI + 0x4c) != 0) {
    FUN_0089120c(*(int *)(unaff_EDI + 0x4c));
  }
  *(undefined4 *)(unaff_EDI + 0x4c) = 0;
  *(undefined4 *)(unaff_EDI + 0x50) = 0;
  *(undefined4 *)(unaff_EDI + 0x54) = 0;
  return;
}

