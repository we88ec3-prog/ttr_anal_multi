
void FUN_0083ee90(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)*param_1;
  piVar2 = (int *)*piVar1;
  *piVar1 = (int)piVar1;
  *(int *)(*param_1 + 4) = *param_1;
  param_1[1] = 0;
  if (piVar2 != (int *)*param_1) {
    do {
      piVar1 = (int *)*piVar2;
      if (piVar2[2] != 0) {
        FUN_0089120c(piVar2[2]);
      }
      piVar2[2] = 0;
      piVar2[3] = 0;
      piVar2[4] = 0;
      FUN_0089120c(piVar2);
      piVar2 = piVar1;
    } while (piVar1 != (int *)*param_1);
  }
  return;
}

