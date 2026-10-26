
void FUN_00bd0c40(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00a084a8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_004ad180(*DAT_00fe3420,DAT_00fe3420);
  FUN_0089120c(DAT_00fe3420,uVar1);
  ExceptionList = local_10;
  return;
}

