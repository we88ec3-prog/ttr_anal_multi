
void FUN_00bcda40(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00a0823a;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_004ca160(*DAT_00fc0e04,DAT_00fc0e04);
  FUN_0089120c(DAT_00fc0e04,uVar1);
  ExceptionList = local_10;
  return;
}

