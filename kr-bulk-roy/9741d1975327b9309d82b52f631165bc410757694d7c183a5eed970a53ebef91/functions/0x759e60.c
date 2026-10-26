
void FUN_00759e60(undefined4 param_1)

{
  undefined4 in_ECX;
  uint in_stack_00000018;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091e518;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_007578f0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_00759ed0(in_ECX,&param_1,in_stack_00000020,in_stack_00000024);
  if (7 < in_stack_00000018) {
    FUN_0089120c(param_1);
  }
  ExceptionList = local_10;
  return;
}

