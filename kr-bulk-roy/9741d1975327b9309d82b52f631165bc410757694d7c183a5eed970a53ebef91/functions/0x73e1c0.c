
void FUN_0073e1c0(int param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090f09d;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_005540c0(**(undefined4 **)(param_1 + 0x1c),*(undefined4 **)(param_1 + 0x1c));
  FUN_0089120c(*(undefined4 *)(param_1 + 0x1c),uVar1);
  local_8 = 2;
  FUN_0073ebe0(**(undefined4 **)(param_1 + 8),*(undefined4 **)(param_1 + 8));
  FUN_0089120c(*(undefined4 *)(param_1 + 8));
  ExceptionList = local_10;
  return;
}

