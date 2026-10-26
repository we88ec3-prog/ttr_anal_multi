
void FUN_005549b0(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091df15;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00555c60(*DAT_00fc1904,DAT_00fc1904);
  FUN_0089120c(DAT_00fc1904,uVar1);
  ExceptionList = local_10;
  return;
}

