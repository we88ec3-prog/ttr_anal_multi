
void FUN_005585f0(void)

{
  int *piVar1;
  int *piVar2;
  int *unaff_EDI;
  
  piVar2 = *(int **)*unaff_EDI;
  if (piVar2 != (int *)*unaff_EDI) {
    do {
      piVar1 = (int *)piVar2[2];
      if (piVar1 != (int *)0x0) {
        if ((int *)*piVar1 != (int *)0x0) {
          (**(code **)(*(int *)*piVar1 + 8))();
          *piVar1 = 0;
        }
        FUN_0089120c(piVar1);
      }
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)*unaff_EDI);
  }
  piVar2 = (int *)*unaff_EDI;
  piVar1 = (int *)*piVar2;
  *piVar2 = (int)piVar2;
  *(int *)(*unaff_EDI + 4) = *unaff_EDI;
  unaff_EDI[1] = 0;
  if (piVar1 != (int *)*unaff_EDI) {
    do {
      piVar2 = (int *)*piVar1;
      FUN_0089120c(piVar1);
      piVar1 = piVar2;
    } while (piVar2 != (int *)*unaff_EDI);
  }
  return;
}

