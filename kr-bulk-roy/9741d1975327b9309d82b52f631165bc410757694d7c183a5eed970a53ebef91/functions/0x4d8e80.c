
void FUN_004d8e80(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00910827;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 3;
  FUN_004e0fc0(param_1 + 0x10,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_005375f0();
  local_8._0_1_ = 4;
  FUN_004db060(**(undefined4 **)(param_1 + 0x24),*(undefined4 **)(param_1 + 0x24));
  FUN_0089120c(*(undefined4 *)(param_1 + 0x24));
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_005540c0(**(undefined4 **)(param_1 + 0x14),*(undefined4 **)(param_1 + 0x14));
  FUN_0089120c(*(undefined4 *)(param_1 + 0x14));
  local_8 = 6;
  FUN_004daf10(**(undefined4 **)(param_1 + 4),*(undefined4 **)(param_1 + 4));
  FUN_0089120c(*(undefined4 *)(param_1 + 4));
  ExceptionList = local_10;
  return;
}

