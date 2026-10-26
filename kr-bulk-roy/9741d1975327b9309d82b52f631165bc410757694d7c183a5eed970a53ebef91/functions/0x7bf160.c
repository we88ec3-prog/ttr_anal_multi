
void FUN_007bf160(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00907785;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_007c0500(*DAT_00fe1b64,DAT_00fe1b64);
  FUN_0089120c(DAT_00fe1b64,uVar1);
  ExceptionList = local_10;
  return;
}

