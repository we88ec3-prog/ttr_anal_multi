
void FUN_004fffb0(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091740b;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CQuestMgr::vftable;
  local_8 = 3;
  iVar1 = param_1[0x17ab];
  if (iVar1 != 0) {
    FUN_005046b0(iVar1);
    FUN_0089120c(iVar1);
    param_1[0x17ab] = 0;
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004ffa40(*(undefined4 *)param_1[0x17bf],(undefined4 *)param_1[0x17bf]);
  FUN_0089120c(param_1[0x17bf],uVar2);
  if (param_1[0x17b0] != 0) {
    FUN_0089120c(param_1[0x17b0],uVar2);
  }
  param_1[0x17b0] = 0;
  param_1[0x17b1] = 0;
  param_1[0x17b2] = 0;
  if (param_1[0x17ac] != 0) {
    FUN_0089120c(param_1[0x17ac],uVar2);
  }
  param_1[0x17ac] = 0;
  param_1[0x17ad] = 0;
  param_1[0x17ae] = 0;
  *param_1 = CPacketProcessor::vftable;
  ExceptionList = local_10;
  return;
}

