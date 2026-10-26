
int FUN_008eca20(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x1dc);
  iVar1 = *(int *)(param_1 + 0x1e0);
  iVar2 = *(int *)(param_1 + 0x1e4) - iVar1;
  if (-1 < param_2) {
    iVar3 = ((iVar2 + param_2 + param_3) / iVar3) * iVar3;
    if ((param_2 != 0) && (iVar3 < 0)) {
      iVar3 = 0;
    }
    return iVar3 + iVar1;
  }
  iVar3 = -((((iVar2 - param_2) + param_3) / iVar3) * iVar3);
  if (0 < iVar3) {
    iVar3 = 0;
  }
  return iVar3 - iVar1;
}

