
void FUN_008ba0c0(undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_2;
  piVar2 = (int *)param_2[1];
  if (iVar1 == 0) {
    *param_1 = piVar2;
  }
  else {
    *(int **)(iVar1 + 4) = piVar2;
  }
  if (piVar2 != (int *)0x0) {
    *piVar2 = iVar1;
    return;
  }
  param_1[1] = iVar1;
  return;
}

