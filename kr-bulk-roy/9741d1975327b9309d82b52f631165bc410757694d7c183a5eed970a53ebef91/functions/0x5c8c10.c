
void FUN_005c8c10(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090f86b;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 2;
  FUN_004ffa40(*(undefined4 *)param_1[0xf],(undefined4 *)param_1[0xf]);
  FUN_0089120c(param_1[0xf],uVar1);
  if (7 < (uint)param_1[0xc]) {
    FUN_0089120c(param_1[7],uVar1);
  }
  param_1[0xc] = 7;
  param_1[0xb] = 0;
  *(undefined2 *)(param_1 + 7) = 0;
  if (7 < (uint)param_1[5]) {
    FUN_0089120c(*param_1,uVar1);
  }
  param_1[5] = 7;
  param_1[4] = 0;
  *(undefined2 *)param_1 = 0;
  ExceptionList = local_10;
  return;
}

