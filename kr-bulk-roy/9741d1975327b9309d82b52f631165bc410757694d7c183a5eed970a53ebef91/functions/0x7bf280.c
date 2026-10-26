
void FUN_007bf280(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00911916;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8._0_1_ = 5;
  local_8._1_3_ = 0;
  FUN_00523fe0(*DAT_00fe1bb4,DAT_00fe1bb4);
  FUN_0089120c(DAT_00fe1bb4,uVar1);
  local_8._0_1_ = 6;
  FUN_006d7120(*DAT_00fe1ba4,DAT_00fe1ba4);
  FUN_0089120c(DAT_00fe1ba4);
  local_8._0_1_ = 7;
  FUN_006d7120(*DAT_00fe1b94,DAT_00fe1b94);
  FUN_0089120c(DAT_00fe1b94);
  local_8._0_1_ = 8;
  FUN_007c0440(*DAT_00fe1b84,DAT_00fe1b84);
  FUN_0089120c(DAT_00fe1b84);
  local_8 = CONCAT31(local_8._1_3_,9);
  FUN_007c0380(*DAT_00fe1b74,DAT_00fe1b74);
  FUN_0089120c(DAT_00fe1b74);
  local_8 = 10;
  FUN_007c0500(*DAT_00fe1b64,DAT_00fe1b64);
  FUN_0089120c(DAT_00fe1b64);
  ExceptionList = local_10;
  return;
}

