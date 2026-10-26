
void FUN_00822830(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00907235;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_008237b0(*DAT_00fb93c0,DAT_00fb93c0);
  FUN_0089120c(DAT_00fb93c0,uVar1);
  ExceptionList = local_10;
  return;
}

