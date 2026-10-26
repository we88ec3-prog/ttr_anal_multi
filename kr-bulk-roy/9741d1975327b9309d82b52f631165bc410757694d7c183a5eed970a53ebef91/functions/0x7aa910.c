
int FUN_007aa910(int param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090a0f5;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_006d7120(**(undefined4 **)(param_1 + 0x2c),*(undefined4 **)(param_1 + 0x2c));
  FUN_0089120c(*(undefined4 *)(param_1 + 0x2c),uVar1);
  local_8 = 0xffffffff;
  FUN_007a5120(param_1 + 8);
  FUN_0089120c(param_1);
  ExceptionList = local_10;
  return param_1;
}

