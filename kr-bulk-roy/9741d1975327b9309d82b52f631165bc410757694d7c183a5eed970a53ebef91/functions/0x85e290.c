
void FUN_0085e290(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00904d45;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_0085f190(*DAT_00fe3518,DAT_00fe3518);
  FUN_0089120c(DAT_00fe3518,uVar1);
  ExceptionList = local_10;
  return;
}

