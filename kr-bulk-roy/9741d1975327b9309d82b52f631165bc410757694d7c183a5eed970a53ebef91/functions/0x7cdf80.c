
void FUN_007cdf80(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00909ee5;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_007d0070(*DAT_00fe3254,DAT_00fe3254);
  FUN_0089120c(DAT_00fe3254,uVar1);
  ExceptionList = local_10;
  return;
}

