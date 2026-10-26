
undefined4 * FUN_0045e950(undefined4 *param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00941618;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007564e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  param_1[0x3b] = 0;
  local_8 = 0;
  *param_1 = FUI::CItemDropHistoryDlg::vftable;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  iVar1 = FUN_00404ba0();
  param_1[0x40] = *(int *)(iVar1 + 0x6920) + 0x50dc;
  ExceptionList = local_10;
  return param_1;
}

