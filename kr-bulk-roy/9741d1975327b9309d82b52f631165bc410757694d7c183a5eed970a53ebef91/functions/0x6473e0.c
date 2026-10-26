
void FUN_006473e0(undefined4 param_1)

{
  uint in_stack_00000018;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092d0e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_004026e0(&param_1,0,0xffffffff);
  FUN_004657e0();
  FUN_00767f50();
  if (7 < in_stack_00000018) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  return;
}

