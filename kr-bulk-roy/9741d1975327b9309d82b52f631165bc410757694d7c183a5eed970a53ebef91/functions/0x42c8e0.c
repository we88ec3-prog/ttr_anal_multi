
void FUN_0042c8e0(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0xdc) == 0) {
    iVar2 = -1;
  }
  else {
    iVar2 = *(int *)(*(int *)(unaff_EDI + 0xdc) + 0x20);
  }
  if (iVar2 != param_1) {
    piVar3 = *(int **)(unaff_EDI + 0xa8);
    if (*(char *)(unaff_EDI + 0xe0) == '\0') {
      while( true ) {
        if (piVar3 == *(int **)(unaff_EDI + 0xac)) {
          *(undefined4 *)(unaff_EDI + 0xdc) = 0;
          return;
        }
        if (*(int *)(*piVar3 + 0x20) == param_1) break;
        piVar3 = piVar3 + 1;
      }
      *(int *)(unaff_EDI + 0xdc) = *piVar3;
      return;
    }
    for (; piVar3 != *(int **)(unaff_EDI + 0xac); piVar3 = piVar3 + 1) {
      piVar1 = (int *)*piVar3;
      if (piVar1[8] == param_1) {
        piVar3 = *(int **)(unaff_EDI + 0xdc);
        if ((piVar3 != (int *)0x0) && (piVar1 != piVar3)) {
          (**(code **)(*piVar3 + 0xa0))(0);
        }
        *(int **)(unaff_EDI + 0xdc) = piVar1;
        (**(code **)(*piVar1 + 0xa0))(1);
        return;
      }
    }
    if (*(int **)(unaff_EDI + 0xdc) != (int *)0x0) {
      (**(code **)(**(int **)(unaff_EDI + 0xdc) + 0xa0))(0);
      *(undefined4 *)(unaff_EDI + 0xdc) = 0;
    }
  }
  return;
}

