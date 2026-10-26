
void FUN_004e81a0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090d6c8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CGuildMgr::vftable;
  local_8 = 0;
  FUN_00797a00(uVar1);
  if (param_1[0x17c5] != 0) {
    FUN_00891d3d(param_1[0x17c5]);
    param_1[0x17c5] = 0;
  }
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_00535ac0(*(undefined4 *)param_1[0x17d0],(undefined4 *)param_1[0x17d0]);
  FUN_0089120c(param_1[0x17d0]);
  if (param_1[0x17c9] != 0) {
    FUN_0089120c(param_1[0x17c9]);
  }
  param_1[0x17c9] = 0;
  param_1[0x17ca] = 0;
  param_1[0x17cb] = 0;
  if (7 < (uint)param_1[0x17c2]) {
    FUN_0089120c(param_1[0x17bd]);
  }
  param_1[0x17c2] = 7;
  param_1[0x17c1] = 0;
  *(undefined2 *)(param_1 + 0x17bd) = 0;
  if (param_1[0x17b8] != 0) {
    FUN_0089120c(param_1[0x17b8]);
  }
  param_1[0x17b8] = 0;
  param_1[0x17b9] = 0;
  param_1[0x17ba] = 0;
  if (param_1[0x17ab] != 0) {
    FUN_0089120c(param_1[0x17ab]);
  }
  param_1[0x17ab] = 0;
  param_1[0x17ac] = 0;
  param_1[0x17ad] = 0;
  *param_1 = CPacketProcessor::vftable;
  ExceptionList = local_10;
  return;
}

