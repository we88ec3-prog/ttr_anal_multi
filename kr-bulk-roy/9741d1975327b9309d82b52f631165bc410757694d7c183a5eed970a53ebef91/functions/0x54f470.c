
void FUN_0054f470(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090ae92;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_0054f570(param_1,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 1;
  FUN_005540c0(**(undefined4 **)(param_1 + 4),*(undefined4 **)(param_1 + 4));
  FUN_0089120c(*(undefined4 *)(param_1 + 4));
  ExceptionList = local_10;
  return;
}

