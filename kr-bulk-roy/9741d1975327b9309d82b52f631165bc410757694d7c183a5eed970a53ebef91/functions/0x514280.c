
void FUN_00514280(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009086a5;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00515dd0(*DAT_00fe3014,DAT_00fe3014);
  FUN_0089120c(DAT_00fe3014,uVar1);
  ExceptionList = local_10;
  return;
}

