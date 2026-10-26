
void FUN_00825ed0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090bff7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_004e1070(param_1,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_0085e680(**(undefined4 **)(param_1 + 0x14),*(undefined4 **)(param_1 + 0x14));
  FUN_0089120c(*(undefined4 *)(param_1 + 0x14));
  local_8 = 3;
  FUN_005540c0(**(undefined4 **)(param_1 + 4),*(undefined4 **)(param_1 + 4));
  FUN_0089120c(*(undefined4 *)(param_1 + 4));
  ExceptionList = local_10;
  return;
}

