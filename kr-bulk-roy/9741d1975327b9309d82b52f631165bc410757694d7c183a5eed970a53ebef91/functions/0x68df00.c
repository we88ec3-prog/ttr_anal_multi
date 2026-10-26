
void FUN_0068df00(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091d004;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = FUI::CPartyMatchingDialog::vftable;
  local_8 = 4;
  _eh_vector_destructor_iterator_(param_1 + 0x10a,0x1c,9,FUN_004fa440);
  local_8._0_1_ = 3;
  _eh_vector_destructor_iterator_(param_1 + 0xcb,0x1c,9,FUN_004fa440);
  local_8 = CONCAT31(local_8._1_3_,2);
  _eh_vector_destructor_iterator_(param_1 + 0x8c,0x1c,9,FUN_004fa440);
  if (param_1[0x88] != 0) {
    FUN_006925b0(uVar1);
    FUN_0089120c(param_1[0x88]);
  }
  param_1[0x88] = 0;
  param_1[0x89] = 0;
  param_1[0x8a] = 0;
  if (param_1[0x84] != 0) {
    FUN_006925b0(uVar1);
    FUN_0089120c(param_1[0x84]);
  }
  param_1[0x84] = 0;
  param_1[0x85] = 0;
  param_1[0x86] = 0;
  local_8 = 0xffffffff;
  *param_1 = FoxUI::FXUIWindowMS::vftable;
  FUN_00756590();
  ExceptionList = local_10;
  return;
}

