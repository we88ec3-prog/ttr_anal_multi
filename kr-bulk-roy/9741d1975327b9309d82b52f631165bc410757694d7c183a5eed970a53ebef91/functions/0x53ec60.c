
void FUN_0053ec60(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00908405;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_0053f180(*DAT_00fe188c,DAT_00fe188c);
  FUN_0089120c(DAT_00fe188c,uVar1);
  ExceptionList = local_10;
  return;
}

