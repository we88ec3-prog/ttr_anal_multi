
void FUN_00489da0(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00906685;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00498690(*DAT_00fd8f00,DAT_00fd8f00);
  FUN_0089120c(DAT_00fd8f00,uVar1);
  ExceptionList = local_10;
  return;
}

