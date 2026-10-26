
void FUN_0048b190(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009089fa;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CClient::vftable;
  param_1[2] = CClient::vftable;
  param_1[0x52] = CClient::vftable;
  param_1[0x80] = CClient::vftable;
  local_8 = 6;
  iVar1 = param_1[0x2fd7];
  if (iVar1 != 0) {
    FUN_00507130(iVar1);
    FUN_0089120c(iVar1);
  }
  if ((undefined4 *)param_1[0x2ff9] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x2ff9])(1,uVar2);
    param_1[0x2ff9] = 0;
  }
  iVar1 = param_1[0x2ff8];
  if (iVar1 != 0) {
    FUN_007a3b70();
    FUN_0089120c(iVar1);
  }
  if (DAT_00fba79c == 1) {
    FUN_0048a970();
  }
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_006dae50(param_1 + 0x300a);
  if (param_1[0x2fff] != 0) {
    FUN_0089120c(param_1[0x2fff]);
  }
  param_1[0x2fff] = 0;
  param_1[0x3000] = 0;
  param_1[0x3001] = 0;
  if (param_1[0x2ffb] != 0) {
    FUN_0089120c(param_1[0x2ffb]);
  }
  param_1[0x2ffb] = 0;
  param_1[0x2ffc] = 0;
  param_1[0x2ffd] = 0;
  param_1[0x80] = CPacketProcessor::vftable;
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_00804460();
  param_1[2] = CFramework::vftable;
  *param_1 = CSingleton<CClient>::vftable;
  DAT_00fb1318 = 0;
  ExceptionList = local_10;
  return;
}

