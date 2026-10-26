
void FUN_00822790(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00907270;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_00823c60(param_1 + 0xc,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (*(int *)(param_1 + 0x1c) != 0) {
    FUN_0089120c(*(int *)(param_1 + 0x1c));
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  local_8 = 2;
  FUN_005540c0(**(undefined4 **)(param_1 + 0x10),*(undefined4 **)(param_1 + 0x10));
  FUN_0089120c(*(undefined4 *)(param_1 + 0x10));
  ExceptionList = local_10;
  return;
}

