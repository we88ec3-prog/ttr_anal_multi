
void FUN_00bcddd0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00a080fa;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_0053e6d0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 1;
  FUN_00498690(*DAT_00fd8f00,DAT_00fd8f00);
  FUN_0089120c(DAT_00fd8f00);
  ExceptionList = local_10;
  return;
}

