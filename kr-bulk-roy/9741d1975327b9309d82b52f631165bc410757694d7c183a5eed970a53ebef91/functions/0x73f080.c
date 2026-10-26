
void FUN_0073f080(undefined4 *param_1)

{
  uint uVar1;
  undefined1 local_18 [4];
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090c9e0;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = param_1 + 7;
  local_8 = 1;
  FUN_0073f170(local_18,*(undefined4 *)param_1[8],(undefined4 *)param_1[8]);
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

