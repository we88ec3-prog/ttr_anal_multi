
void FUN_00bce450(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00a082ea;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_0082aa20(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 1;
  FUN_0082ab50(*DAT_00fc16f0,DAT_00fc16f0);
  FUN_0089120c(DAT_00fc16f0);
  ExceptionList = local_10;
  return;
}

