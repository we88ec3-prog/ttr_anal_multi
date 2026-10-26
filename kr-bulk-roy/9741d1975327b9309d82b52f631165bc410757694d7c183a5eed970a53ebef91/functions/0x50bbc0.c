
void FUN_0050bbc0(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 int param_6)

{
  int iVar1;
  
  if (0x28 < param_6 - param_2) {
    iVar1 = (param_6 - param_2) + 1;
    iVar1 = (int)((iVar1 >> 0x1f & 7U) + iVar1) >> 3;
    FUN_0050c0a0(param_1,param_2,param_1,param_2 + iVar1,param_1,iVar1 * 2 + param_2);
    FUN_0050c0a0(param_3,param_4 - iVar1,param_3,param_4,param_3,param_4 + iVar1);
    FUN_0050c0a0(param_5,param_6 + iVar1 * -2,param_5,param_6 - iVar1,param_5,param_6);
    FUN_0050c0a0(param_1,iVar1 + param_2,param_3,param_4,param_5,param_6 - iVar1);
    return;
  }
  FUN_0050c0a0(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

