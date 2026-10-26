
void FUN_00633f80(undefined4 param_1)

{
  uint in_stack_00000018;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090ab98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_0040aff0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (7 < in_stack_00000018) {
    FUN_0089120c(param_1);
  }
  ExceptionList = local_10;
  return;
}

