
void FUN_007ab770(void)

{
  int *piVar1;
  int *piVar2;
  int *unaff_EDI;
  
  piVar2 = *(int **)*unaff_EDI;
  if (piVar2 != (int *)*unaff_EDI) {
    do {
      if ((undefined4 *)piVar2[2] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)piVar2[2])(1);
        piVar2[2] = 0;
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

