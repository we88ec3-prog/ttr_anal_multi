
void FUN_006d6ce0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00916097;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_006d7420(param_1,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_00535ac0(**(undefined4 **)(param_1 + 0x14),*(undefined4 **)(param_1 + 0x14));
  FUN_0089120c(*(undefined4 *)(param_1 + 0x14));
  local_8 = 3;
  FUN_006d7120(**(undefined4 **)(param_1 + 4),*(undefined4 **)(param_1 + 4));
  FUN_0089120c(*(undefined4 *)(param_1 + 4));
  ExceptionList = local_10;
  return;
}

