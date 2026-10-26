
void FUN_00bcee30(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00a0814a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00830c80(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 1;
  FUN_00830900(*DAT_00fe1da8,DAT_00fe1da8);
  FUN_0089120c(DAT_00fe1da8);
  ExceptionList = local_10;
  return;
}

