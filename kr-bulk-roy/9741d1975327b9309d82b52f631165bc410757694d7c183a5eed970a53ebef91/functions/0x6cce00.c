
void FUN_006cce00(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0090a98a;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 5;
  uStack_7 = 0;
  FUN_00535ac0(*(undefined4 *)param_1[0x1d],(undefined4 *)param_1[0x1d]);
  FUN_0089120c(param_1[0x1d],uVar1);
  local_8 = 6;
  FUN_00535ac0(*(undefined4 *)param_1[0x19],(undefined4 *)param_1[0x19]);
  FUN_0089120c(param_1[0x19]);
  local_8 = 7;
  FUN_00535ac0(*(undefined4 *)param_1[0x15],(undefined4 *)param_1[0x15]);
  FUN_0089120c(param_1[0x15]);
  _local_8 = CONCAT31(uStack_7,8);
  FUN_00535ac0(*(undefined4 *)param_1[0x11],(undefined4 *)param_1[0x11]);
  FUN_0089120c(param_1[0x11]);
  if (0xf < (uint)param_1[0xc]) {
    FUN_0089120c(param_1[7]);
  }
  param_1[0xc] = 0xf;
  param_1[0xb] = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  if (0xf < (uint)param_1[5]) {
    FUN_0089120c(*param_1);
  }
  param_1[5] = 0xf;
  param_1[4] = 0;
  *(undefined1 *)param_1 = 0;
  ExceptionList = local_10;
  return;
}

