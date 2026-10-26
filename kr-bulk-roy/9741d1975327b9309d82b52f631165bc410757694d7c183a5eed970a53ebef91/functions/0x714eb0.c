
void FUN_00714eb0(void)

{
  int *piVar1;
  int *piVar2;
  int *unaff_EDI;
  
  piVar1 = (int *)*unaff_EDI;
  piVar2 = (int *)*piVar1;
  *piVar1 = (int)piVar1;
  *(int *)(*unaff_EDI + 4) = *unaff_EDI;
  unaff_EDI[1] = 0;
  if (piVar2 != (int *)*unaff_EDI) {
    do {
      piVar1 = (int *)*piVar2;
      FUN_00714bd0();
      FUN_0089120c(piVar2);
      piVar2 = piVar1;
    } while (piVar1 != (int *)*unaff_EDI);
  }
  return;
}

