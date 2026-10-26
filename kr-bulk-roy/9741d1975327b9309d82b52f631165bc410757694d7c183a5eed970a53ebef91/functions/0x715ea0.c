
void FUN_00715ea0(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090a7f5;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00716c70(*DAT_00fe1e00,DAT_00fe1e00);
  FUN_0089120c(DAT_00fe1e00,uVar1);
  ExceptionList = local_10;
  return;
}

