
void FUN_006bb470(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00916150;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = FUI::CScenarioEntryDummy::vftable;
  local_8 = 0;
  if (param_1[0x3d] != 0) {
    FUN_0089120c(param_1[0x3d],uVar1);
  }
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_004ca160(*(undefined4 *)param_1[0x3a],(undefined4 *)param_1[0x3a]);
  FUN_0089120c(param_1[0x3a],uVar1);
  local_8 = 0xffffffff;
  *param_1 = FoxUI::FXUIDummy::vftable;
  FUN_00745380();
  ExceptionList = local_10;
  return;
}

