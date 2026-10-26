
void FUN_0050cde0(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00912f5c;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  FUN_00535ac0(*DAT_00fe17f4,DAT_00fe17f4);
  FUN_0089120c(DAT_00fe17f4,uVar1);
  local_8._0_1_ = 4;
  FUN_0050e0e0(*DAT_00fe17e4,DAT_00fe17e4);
  FUN_0089120c(DAT_00fe17e4);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_0050dfe0(*DAT_00fe17d4,DAT_00fe17d4);
  FUN_0089120c(DAT_00fe17d4);
  local_8 = 6;
  FUN_0050df40(*DAT_00fe17c4,DAT_00fe17c4);
  FUN_0089120c(DAT_00fe17c4);
  ExceptionList = local_10;
  return;
}

