
void FUN_007501e0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int unaff_EDI;
  
  piVar1 = *(int **)(unaff_EDI + 0x1480);
  piVar2 = (int *)*piVar1;
  while (piVar3 = piVar2, piVar3 != piVar1) {
    if (*(int *)(piVar3[2] + 8) == param_1) {
      piVar2 = (int *)*piVar3;
      if (piVar3 != *(int **)(unaff_EDI + 0x1480)) {
        *(int *)piVar3[1] = *piVar3;
        *(int *)(*piVar3 + 4) = piVar3[1];
        FUN_0089120c(piVar3);
        *(int *)(unaff_EDI + 0x1484) = *(int *)(unaff_EDI + 0x1484) + -1;
      }
    }
    else {
      piVar2 = (int *)*piVar3;
    }
  }
  return;
}

