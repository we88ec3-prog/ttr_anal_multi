
undefined4 FUN_00569280(undefined4 param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009383c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = param_1;
  local_18 = 0;
  local_14 = 0;
  local_8 = 0;
  FUN_0056a5f0(&local_1c,DAT_00fe27d4,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  ExceptionList = local_10;
  return 1;
}

