
void FUN_00bcf140(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00a084f5;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_005367c0(*DAT_00fe36f4,DAT_00fe36f4);
  FUN_0089120c(DAT_00fe36f4,uVar1);
  ExceptionList = local_10;
  return;
}

