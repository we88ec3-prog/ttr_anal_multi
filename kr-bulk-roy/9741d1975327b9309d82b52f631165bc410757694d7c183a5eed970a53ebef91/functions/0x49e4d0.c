
void FUN_0049e4d0(void)

{
  undefined4 in_stack_00000010;
  uint in_stack_00000024;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00910a88;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_0049e530(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (7 < in_stack_00000024) {
    FUN_0089120c(in_stack_00000010);
  }
  ExceptionList = local_10;
  return;
}

