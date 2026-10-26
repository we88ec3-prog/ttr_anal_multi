
void FUN_00552640(int *param_1)

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
      if (0xf < (uint)piVar2[7]) {
        FUN_0089120c(piVar2[2]);
      }
      piVar2[7] = 0xf;
      piVar2[6] = 0;
      *(undefined1 *)(piVar2 + 2) = 0;
      FUN_0089120c(piVar2);
      piVar2 = piVar1;
    } while (piVar1 != (int *)*param_1);
  }
  return;
}

