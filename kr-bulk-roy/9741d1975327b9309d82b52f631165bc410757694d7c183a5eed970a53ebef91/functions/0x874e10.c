
int * FUN_00874e10(int *param_1,int param_2,int param_3)

{
  uint *in_EAX;
  int iVar1;
  int iVar2;
  
  iVar2 = param_3 - param_2 >> 2;
  if (0 < iVar2) {
    do {
      iVar1 = iVar2 / 2;
      if (*(uint *)(param_2 + iVar1 * 4) < *in_EAX) {
        param_2 = param_2 + 4 + iVar1 * 4;
        iVar1 = iVar2 + (-1 - iVar1);
      }
      iVar2 = iVar1;
    } while (0 < iVar1);
  }
  *param_1 = param_2;
  return param_1;
}

