
/* WARNING: Removing unreachable block (ram,0x00454bec) */
/* WARNING: Removing unreachable block (ram,0x00454bf0) */

void FUN_00454ba0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091bb3e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = FUI::CInfiniteDungeonEntryDlg::vftable;
  local_8 = 0;
  if (param_1[0x60] != param_1[0x61]) {
    param_1[0x61] = param_1[0x60];
  }
  if (param_1[0x60] != 0) {
    FUN_0089120c(param_1[0x60],uVar1);
  }
  param_1[0x60] = 0;
  param_1[0x61] = 0;
  param_1[0x62] = 0;
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_004ca160(*(undefined4 *)param_1[0x5a],(undefined4 *)param_1[0x5a]);
  FUN_0089120c(param_1[0x5a],uVar1);
  if (param_1[0x55] != 0) {
    FUN_0089120c(param_1[0x55],uVar1);
  }
  param_1[0x55] = 0;
  param_1[0x56] = 0;
  param_1[0x57] = 0;
  local_8 = 0xffffffff;
  *param_1 = FoxUI::FXUIWindowClose::vftable;
  FUN_00756590();
  ExceptionList = local_10;
  return;
}

