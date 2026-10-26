
int FUN_006f9340(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *local_8;
  
  iVar3 = 0;
  iVar2 = 0;
  iVar4 = 0;
  iVar1 = 1;
  if (*param_2 < 1) {
    *param_2 = 0;
    return 0;
  }
  local_8 = param_1;
  while( true ) {
    if ((0 < *local_8) && (iVar3 = iVar3 + *local_8, iVar1 / 2 < iVar3)) {
      iVar2 = iVar3;
      iVar4 = iVar1;
    }
    if (iVar3 == *param_2) break;
    local_8 = local_8 + 1;
    iVar1 = iVar1 * 2;
    if (*param_2 <= iVar1 / 2) {
      *param_2 = iVar4;
      return iVar2;
    }
  }
  *param_2 = iVar4;
  return iVar2;
}

