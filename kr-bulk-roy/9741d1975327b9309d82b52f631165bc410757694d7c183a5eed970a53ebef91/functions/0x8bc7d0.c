
int FUN_008bc7d0(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                int *param_6)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  iVar1 = FUN_008baf40(param_1,param_2,param_3,param_4,param_5,&local_8);
  if (local_8 != 0) {
    *param_6 = local_8;
    return iVar1;
  }
  if (param_3 < param_4) {
    _memset((void *)(param_2 * param_3 + iVar1),0,(param_4 - param_3) * param_2);
    *param_6 = local_8;
    return iVar1;
  }
  *param_6 = 0;
  return iVar1;
}

