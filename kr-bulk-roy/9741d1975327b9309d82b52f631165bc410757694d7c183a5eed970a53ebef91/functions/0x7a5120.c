
void FUN_007a5120(int param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090788a;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_006d7120(**(undefined4 **)(param_1 + 0x14),*(undefined4 **)(param_1 + 0x14));
  FUN_0089120c(*(undefined4 *)(param_1 + 0x14),uVar1);
  local_8 = 2;
  FUN_004ca160(**(undefined4 **)(param_1 + 4),*(undefined4 **)(param_1 + 4));
  FUN_0089120c(*(undefined4 *)(param_1 + 4));
  ExceptionList = local_10;
  return;
}

