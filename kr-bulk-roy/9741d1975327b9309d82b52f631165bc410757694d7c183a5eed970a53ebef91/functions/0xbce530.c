
void FUN_00bce530(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00a081a5;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_004d3680(*DAT_00fc7f10,DAT_00fc7f10);
  FUN_0089120c(DAT_00fc7f10,uVar1);
  ExceptionList = local_10;
  return;
}

