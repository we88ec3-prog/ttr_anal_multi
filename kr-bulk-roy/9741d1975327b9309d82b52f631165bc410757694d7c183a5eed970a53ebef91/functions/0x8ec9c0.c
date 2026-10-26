
int FUN_008ec9c0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_1 + 0x1e0);
  iVar2 = *(int *)(param_1 + 0x1e4) - iVar1;
  if (-1 < param_2) {
    uVar3 = iVar2 + param_2 + param_3 & -*(int *)(param_1 + 0x1dc);
    if ((param_2 != 0) && ((int)uVar3 < 0)) {
      uVar3 = 0;
    }
    return uVar3 + iVar1;
  }
  iVar2 = -((iVar2 - param_2) + param_3 & -*(int *)(param_1 + 0x1dc));
  if (0 < iVar2) {
    iVar2 = 0;
  }
  return iVar2 - iVar1;
}

