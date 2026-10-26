
void FUN_004dc600(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00908855;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_004dd530(*DAT_00fab0e0,DAT_00fab0e0);
  FUN_0089120c(DAT_00fab0e0,uVar1);
  ExceptionList = local_10;
  return;
}

