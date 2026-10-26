
void FUN_00434f00(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091bcf0;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = FUI::CEternalTowerEntryDlg::vftable;
  local_8 = 1;
  FUN_004ca160(*(undefined4 *)param_1[0x52],(undefined4 *)param_1[0x52]);
  FUN_0089120c(param_1[0x52],uVar1);
  local_8 = 0xffffffff;
  *param_1 = FoxUI::FXUIWindowClose::vftable;
  FUN_00756590();
  ExceptionList = local_10;
  return;
}

