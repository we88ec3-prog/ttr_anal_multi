
void FUN_00bd08a0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00a0809a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00783e60(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 1;
  FUN_00783ed0(*DAT_00fe31f0,DAT_00fe31f0);
  FUN_0089120c(DAT_00fe31f0);
  ExceptionList = local_10;
  return;
}

