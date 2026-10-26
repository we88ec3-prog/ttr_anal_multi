
int FUN_008c48c0(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  
  if (0xfffe < *param_2) {
    return 0;
  }
  if ((*(byte *)(param_1 + 0x14) & 1) != 0) {
    iVar2 = FUN_008c41a0(param_1,param_2,1);
    return iVar2;
  }
  if (*param_2 == *(uint *)(param_1 + 0x18)) {
    FUN_008c3d40();
    iVar1 = *(int *)(param_1 + 0x1c);
    iVar2 = 0;
    if (iVar1 != 0) {
      *param_2 = *(uint *)(param_1 + 0x18);
      return iVar1;
    }
  }
  else {
    iVar2 = FUN_008c4370(param_1,param_2,1);
  }
  return iVar2;
}

