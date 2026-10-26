
void FUN_00bcdd60(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00a0820a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_004c66c0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 1;
  FUN_004c6860(*DAT_00fd9268,DAT_00fd9268);
  FUN_0089120c(DAT_00fd9268);
  ExceptionList = local_10;
  return;
}

