
void FUN_008226d0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009096bb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
  FUN_00823ba0(param_1 + 0x48,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_005540c0(**(undefined4 **)(param_1 + 0x4c),*(undefined4 **)(param_1 + 0x4c));
  FUN_0089120c(*(undefined4 *)(param_1 + 0x4c));
  if (7 < *(uint *)(param_1 + 0x40)) {
    FUN_0089120c(*(undefined4 *)(param_1 + 0x2c));
  }
  *(undefined4 *)(param_1 + 0x40) = 7;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined2 *)(param_1 + 0x2c) = 0;
  if (7 < *(uint *)(param_1 + 0x24)) {
    FUN_0089120c(*(undefined4 *)(param_1 + 0x10));
  }
  *(undefined4 *)(param_1 + 0x24) = 7;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined2 *)(param_1 + 0x10) = 0;
  ExceptionList = local_10;
  return;
}

