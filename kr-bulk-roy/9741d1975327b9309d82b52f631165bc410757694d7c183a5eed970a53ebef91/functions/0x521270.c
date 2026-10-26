
void FUN_00521270(void)

{
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_0090d1c7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_00523ea0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = local_8 & 0xffffff00;
  FUN_00521180(&DAT_00f8d9bc);
  local_8 = 2;
  FUN_00523750(*DAT_00f8d9b0,DAT_00f8d9b0);
  FUN_0089120c(DAT_00f8d9b0);
  ExceptionList = local_10;
  return;
}

