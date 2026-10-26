
void FUN_0085a2f0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0090bb93;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = gbDxEffect::vftable;
  local_8 = 7;
  FUN_0085a440(param_1);
  if (param_1[0x23] != 0) {
    FUN_0089120c(param_1[0x23],uVar1);
  }
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  local_8._0_1_ = 8;
  FUN_0085e680(*(undefined4 *)param_1[0x1d],(undefined4 *)param_1[0x1d]);
  FUN_0089120c(param_1[0x1d],uVar1);
  local_8 = CONCAT31(local_8._1_3_,9);
  FUN_0085e680(*(undefined4 *)param_1[0x19],(undefined4 *)param_1[0x19]);
  FUN_0089120c(param_1[0x19]);
  if (param_1[0x14] != 0) {
    FUN_0089120c(param_1[0x14]);
  }
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  local_8._0_1_ = 10;
  FUN_0085e530(*(undefined4 *)param_1[0x11],(undefined4 *)param_1[0x11]);
  FUN_0089120c(param_1[0x11]);
  local_8._0_1_ = 0xb;
  FUN_0085e3e0(*(undefined4 *)param_1[0xd],(undefined4 *)param_1[0xd]);
  FUN_0089120c(param_1[0xd]);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0083f1b0(param_1 + 8);
  if (param_1[4] != 0) {
    FUN_0089120c(param_1[4]);
  }
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  ExceptionList = local_10;
  return;
}

