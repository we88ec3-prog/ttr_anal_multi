
void FUN_00bcf1b0(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00a082c5;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_007c3150(*DAT_00fe1e10,DAT_00fe1e10);
  FUN_0089120c(DAT_00fe1e10,uVar1);
  ExceptionList = local_10;
  return;
}

