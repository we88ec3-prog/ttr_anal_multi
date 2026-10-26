
void FUN_008ba0f0(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_2;
  piVar2 = (int *)param_2[1];
  if (iVar1 != 0) {
    *(int **)(iVar1 + 4) = piVar2;
    if (piVar2 != (int *)0x0) {
      *piVar2 = iVar1;
      *param_2 = 0;
      param_2[1] = *param_1;
      *(int **)*param_1 = param_2;
      *param_1 = (int)param_2;
      return;
    }
    param_1[1] = iVar1;
    *param_2 = 0;
    param_2[1] = *param_1;
    *(int **)*param_1 = param_2;
    *param_1 = (int)param_2;
  }
  return;
}

