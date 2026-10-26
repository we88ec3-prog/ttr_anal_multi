
void FUN_004f1170(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = CMessengerMgr::vftable;
  FUN_00797a00();
  FUN_00797a00();
  FUN_00797a00();
  iVar1 = param_1[0x17b4];
  if (iVar1 != 0) {
    FUN_0089120c(iVar1);
  }
  param_1[0x17b4] = 0;
  param_1[0x17b5] = 0;
  param_1[0x17b6] = 0;
  if (param_1[0x17af] != 0) {
    FUN_0089120c(param_1[0x17af]);
  }
  param_1[0x17af] = 0;
  param_1[0x17b0] = 0;
  param_1[0x17b1] = 0;
  if (param_1[0x17ab] != 0) {
    FUN_0089120c(param_1[0x17ab]);
  }
  param_1[0x17ab] = 0;
  param_1[0x17ac] = 0;
  param_1[0x17ad] = 0;
  *param_1 = CPacketProcessor::vftable;
  return;
}

