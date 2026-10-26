
void FUN_00bcde40(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00a083f5;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00828ba0(*DAT_00fd93fc,DAT_00fd93fc);
  FUN_0089120c(DAT_00fd93fc,uVar1);
  ExceptionList = local_10;
  return;
}

