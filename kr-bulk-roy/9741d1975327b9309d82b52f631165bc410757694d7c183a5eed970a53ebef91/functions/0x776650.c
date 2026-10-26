
void FUN_00776650(void)

{
  int *piVar1;
  int *piVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 4) != unaff_ESI) {
    if (((unaff_ESI != 0) && (piVar2 = *(int **)(unaff_ESI + 8), piVar2 != (int *)0x0)) &&
       (piVar2[0x27] = piVar2[0x27] + 1, piVar2[0x27] == 1)) {
      (**(code **)(*piVar2 + 0x24))();
    }
    if ((*(int *)(unaff_EDI + 4) != 0) &&
       (piVar2 = *(int **)(*(int *)(unaff_EDI + 4) + 8), piVar2 != (int *)0x0)) {
      piVar1 = piVar2 + 0x27;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(code **)(*piVar2 + 0x28))();
      }
    }
    *(int *)(unaff_EDI + 4) = unaff_ESI;
  }
  return;
}

