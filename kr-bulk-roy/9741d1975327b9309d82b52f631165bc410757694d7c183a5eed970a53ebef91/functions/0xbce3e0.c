
void FUN_00bce3e0(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00a084d5;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00829bc0(*DAT_00fc1b08,DAT_00fc1b08);
  FUN_0089120c(DAT_00fc1b08,uVar1);
  ExceptionList = local_10;
  return;
}

