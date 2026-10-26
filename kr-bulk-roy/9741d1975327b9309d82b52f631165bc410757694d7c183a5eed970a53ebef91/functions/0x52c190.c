
void FUN_0052c190(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00910124;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  FUN_0052d350(*DAT_00fc0d34,DAT_00fc0d34);
  FUN_0089120c(DAT_00fc0d34,uVar1);
  local_8._0_1_ = 4;
  FUN_0052d2b0(*DAT_00fc0d24,DAT_00fc0d24);
  FUN_0089120c(DAT_00fc0d24);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_00833ad0(*DAT_00fc0d14,DAT_00fc0d14);
  FUN_0089120c(DAT_00fc0d14);
  local_8 = 6;
  FUN_00833ad0(*DAT_00fc0d04,DAT_00fc0d04);
  FUN_0089120c(DAT_00fc0d04);
  ExceptionList = local_10;
  return;
}

