
void FUN_00514460(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00917266;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8._0_1_ = 7;
  local_8._1_3_ = 0;
  FUN_00516150(*DAT_00fe3090,DAT_00fe3090);
  FUN_0089120c(DAT_00fe3090,uVar1);
  local_8._0_1_ = 8;
  FUN_00535ac0(*DAT_00fe3080,DAT_00fe3080);
  FUN_0089120c(DAT_00fe3080);
  local_8._0_1_ = 9;
  FUN_005160b0(*DAT_00fe3070,DAT_00fe3070);
  FUN_0089120c(DAT_00fe3070);
  local_8._0_1_ = 10;
  FUN_00515ff0(*DAT_00fe3060,DAT_00fe3060);
  FUN_0089120c(DAT_00fe3060);
  local_8._0_1_ = 0xb;
  FUN_00515f30(*DAT_00fe3044,DAT_00fe3044);
  FUN_0089120c(DAT_00fe3044);
  local_8 = CONCAT31(local_8._1_3_,0xc);
  FUN_00515e70(*DAT_00fe3034,DAT_00fe3034);
  FUN_0089120c(DAT_00fe3034);
  if (DAT_00fe3020 != 0) {
    FUN_0089120c(DAT_00fe3020);
  }
  DAT_00fe3020 = 0;
  DAT_00fe3024 = 0;
  DAT_00fe3028 = 0;
  local_8 = 0xd;
  FUN_00515dd0(*DAT_00fe3014,DAT_00fe3014);
  FUN_0089120c(DAT_00fe3014);
  ExceptionList = local_10;
  return;
}

