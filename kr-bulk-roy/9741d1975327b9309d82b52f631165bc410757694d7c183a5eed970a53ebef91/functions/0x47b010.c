
void FUN_0047b010(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090b6a2;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  FUN_0047bbc0(*DAT_00fc0fac,DAT_00fc0fac);
  FUN_0089120c(DAT_00fc0fac,uVar1);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004ca160(*DAT_00fc0f9c,DAT_00fc0f9c);
  FUN_0089120c(DAT_00fc0f9c);
  local_8 = 4;
  FUN_005540c0(*DAT_00fc0f8c,DAT_00fc0f8c);
  FUN_0089120c(DAT_00fc0f8c);
  ExceptionList = local_10;
  return;
}

