
void FUN_0060d630(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091f780;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = FUI::CSkillSlotToolTip::vftable;
  local_8 = 0;
  if (7 < (uint)param_1[0x79]) {
    FUN_0089120c(param_1[0x74],uVar1);
  }
  param_1[0x79] = 7;
  param_1[0x78] = 0;
  *(undefined2 *)(param_1 + 0x74) = 0;
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_004ca160(*(undefined4 *)param_1[0x6a],(undefined4 *)param_1[0x6a]);
  FUN_0089120c(param_1[0x6a],uVar1);
  local_8 = 0xffffffff;
  *param_1 = FoxUI::FXUIStatic::vftable;
  FUN_00754980();
  ExceptionList = local_10;
  return;
}

