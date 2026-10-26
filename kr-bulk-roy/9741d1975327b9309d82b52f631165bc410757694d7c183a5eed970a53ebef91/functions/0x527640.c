
void FUN_00527640(void)

{
  int *piVar1;
  int *piVar2;
  int *unaff_ESI;
  
  piVar1 = (int *)*unaff_ESI;
  piVar2 = (int *)*piVar1;
  *piVar1 = (int)piVar1;
  *(int *)(*unaff_ESI + 4) = *unaff_ESI;
  unaff_ESI[1] = 0;
  if (piVar2 != (int *)*unaff_ESI) {
    do {
      piVar1 = (int *)*piVar2;
      FUN_0089120c(piVar2);
      piVar2 = piVar1;
    } while (piVar1 != (int *)*unaff_ESI);
  }
  return;
}

