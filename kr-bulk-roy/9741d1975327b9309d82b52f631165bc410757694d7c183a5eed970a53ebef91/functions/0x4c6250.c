
void FUN_004c6250(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00908945;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_004c6860(*DAT_00fd9268,DAT_00fd9268);
  FUN_0089120c(DAT_00fd9268,uVar1);
  ExceptionList = local_10;
  return;
}

