
void FUN_004e1b70(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090d79e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CGlobalStatus::vftable;
  local_8 = 0;
  if (param_1[0x1a66] != 0) {
    FUN_0089120c(param_1[0x1a66],uVar1);
  }
  param_1[0x1a66] = 0;
  param_1[0x1a67] = 0;
  param_1[0x1a68] = 0;
  if (param_1[0x1a4e] != 0) {
    FUN_0089120c(param_1[0x1a4e],uVar1);
  }
  param_1[0x1a4e] = 0;
  param_1[0x1a4f] = 0;
  param_1[0x1a50] = 0;
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_0081cd10(*(undefined4 *)param_1[0x1a44],(undefined4 *)param_1[0x1a44]);
  FUN_0089120c(param_1[0x1a44],uVar1);
  if (param_1[0x1a3f] != 0) {
    FUN_0089120c(param_1[0x1a3f],uVar1);
  }
  param_1[0x1a3f] = 0;
  param_1[0x1a40] = 0;
  param_1[0x1a41] = 0;
  *param_1 = CPacketProcessor::vftable;
  ExceptionList = local_10;
  return;
}

