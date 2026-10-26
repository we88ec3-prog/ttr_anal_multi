
void FUN_00753830(void)

{
  int *piVar1;
  int *unaff_ESI;
  int *piVar2;
  
  piVar2 = *(int **)*unaff_ESI;
  if (piVar2 != (int *)*unaff_ESI) {
    do {
      if ((int *)piVar2[2] != (int *)0x0) {
        (**(code **)(*(int *)piVar2[2] + 0x10))(1);
      }
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)*unaff_ESI);
  }
  piVar2 = (int *)*unaff_ESI;
  piVar1 = (int *)*piVar2;
  *piVar2 = (int)piVar2;
  *(int *)(*unaff_ESI + 4) = *unaff_ESI;
  unaff_ESI[1] = 0;
  if (piVar1 != (int *)*unaff_ESI) {
    do {
      piVar2 = (int *)*piVar1;
      FUN_0089120c(piVar1);
      piVar1 = piVar2;
    } while (piVar2 != (int *)*unaff_ESI);
  }
  return;
}

