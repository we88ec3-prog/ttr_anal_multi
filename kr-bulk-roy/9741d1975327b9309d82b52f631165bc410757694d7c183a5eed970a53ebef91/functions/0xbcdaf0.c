
void FUN_00bcdaf0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00a083a5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_0047e9a0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 1;
  FUN_005540c0(*DAT_00fc0f6c,DAT_00fc0f6c);
  FUN_0089120c(DAT_00fc0f6c);
  ExceptionList = local_10;
  return;
}

