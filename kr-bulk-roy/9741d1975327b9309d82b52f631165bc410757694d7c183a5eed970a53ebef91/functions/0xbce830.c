
void FUN_00bce830(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00a0817a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_0053f580(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 1;
  FUN_0053f180(*DAT_00fe188c,DAT_00fe188c);
  FUN_0089120c(DAT_00fe188c);
  ExceptionList = local_10;
  return;
}

