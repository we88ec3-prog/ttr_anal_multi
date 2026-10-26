
void FUN_0044ae30(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00908b05;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_0044b720(*DAT_00fb9398,DAT_00fb9398);
  FUN_0089120c(DAT_00fb9398,uVar1);
  ExceptionList = local_10;
  return;
}

