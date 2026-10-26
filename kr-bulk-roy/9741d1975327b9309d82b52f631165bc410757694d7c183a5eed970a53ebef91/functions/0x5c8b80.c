
void FUN_005c8b80(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00912830;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_005c8ed0(*(undefined4 *)param_1[8],(undefined4 *)param_1[8]);
  FUN_0089120c(param_1[8],uVar1);
  if (7 < (uint)param_1[5]) {
    FUN_0089120c(*param_1,uVar1);
  }
  param_1[5] = 7;
  param_1[4] = 0;
  *(undefined2 *)param_1 = 0;
  ExceptionList = local_10;
  return;
}

