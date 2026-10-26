
void FUN_007b56f0(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009077a5;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_007b6de0(*DAT_00fd9424,DAT_00fd9424);
  FUN_0089120c(DAT_00fd9424,uVar1);
  ExceptionList = local_10;
  return;
}

