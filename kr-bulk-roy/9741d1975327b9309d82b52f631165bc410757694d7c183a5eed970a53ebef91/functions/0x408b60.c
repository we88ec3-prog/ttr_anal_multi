
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00408b60(void)

{
  int *piVar1;
  int *piVar2;
  int unaff_ESI;
  
  piVar1 = *(int **)(unaff_ESI + 0xdc);
  if (piVar1 != (int *)0x0) {
    piVar2 = *(int **)(unaff_ESI + 0xa8);
    if (*(char *)(unaff_ESI + 0xe0) != '\0') {
      while( true ) {
        if (piVar2 == *(int **)(unaff_ESI + 0xac)) {
          (**(code **)(*piVar1 + 0xa0))(0);
          *(undefined4 *)(unaff_ESI + 0xdc) = 0;
          return;
        }
        if (*piVar2 == 0) break;
        piVar2 = piVar2 + 1;
      }
      (**(code **)(*piVar1 + 0xa0))(0);
      *(undefined4 *)(unaff_ESI + 0xdc) = 0;
      (**(code **)(_DAT_00000000 + 0xa0))(1);
      return;
    }
    for (; (piVar2 != *(int **)(unaff_ESI + 0xac) && (*piVar2 != 0)); piVar2 = piVar2 + 1) {
    }
    *(undefined4 *)(unaff_ESI + 0xdc) = 0;
  }
  return;
}

