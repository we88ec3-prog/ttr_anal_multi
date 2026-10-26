
void FUN_00bcd5a0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00a083ca;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00823d90(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 1;
  FUN_008237b0(*DAT_00fb93c0,DAT_00fb93c0);
  FUN_0089120c(DAT_00fb93c0);
  ExceptionList = local_10;
  return;
}

