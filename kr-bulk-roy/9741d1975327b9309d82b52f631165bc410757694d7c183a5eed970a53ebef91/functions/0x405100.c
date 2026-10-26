
void FUN_00405100(undefined4 param_1,undefined4 param_2)

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
  FUN_00405030(unaff_ESI,*(undefined4 *)*unaff_ESI,param_1,param_2,param_2);
  return;
}

