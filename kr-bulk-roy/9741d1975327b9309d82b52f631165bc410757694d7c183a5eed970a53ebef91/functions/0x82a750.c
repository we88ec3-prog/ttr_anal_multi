
void FUN_0082a750(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00909575;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_0082ab50(*DAT_00fc16f0,DAT_00fc16f0);
  FUN_0089120c(DAT_00fc16f0,uVar1);
  ExceptionList = local_10;
  return;
}

