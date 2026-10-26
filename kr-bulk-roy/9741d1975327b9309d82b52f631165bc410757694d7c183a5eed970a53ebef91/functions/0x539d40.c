
void FUN_00539d40(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090fe7d;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CPartyMgr::vftable;
  local_8 = 2;
  FUN_0053bed0(param_1 + 0x17b2,uVar1);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_005540c0(*(undefined4 *)param_1[0x17b3],(undefined4 *)param_1[0x17b3]);
  FUN_0089120c(param_1[0x17b3]);
  if (param_1[0x17ae] != 0) {
    FUN_0089120c(param_1[0x17ae]);
  }
  param_1[0x17ae] = 0;
  param_1[0x17af] = 0;
  param_1[0x17b0] = 0;
  *param_1 = CPacketProcessor::vftable;
  ExceptionList = local_10;
  return;
}

