
void FUN_008ba090(undefined4 *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = param_1[1];
  param_2[1] = 0;
  *param_2 = iVar1;
  if (iVar1 != 0) {
    *(int **)(iVar1 + 4) = param_2;
    param_1[1] = param_2;
    return;
  }
  *param_1 = param_2;
  param_1[1] = param_2;
  return;
}

