
undefined4 * FUN_0064ce10(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00919fc8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00744320(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  *param_1 = FoxUI::FXUIButton::vftable;
  FUN_0077b520(param_1 + 0x2a);
  *(undefined1 *)(param_1 + 0x29) = 1;
  *param_1 = FUI::CKeyDescBtnBigMap::vftable;
  ExceptionList = local_10;
  return param_1;
}

