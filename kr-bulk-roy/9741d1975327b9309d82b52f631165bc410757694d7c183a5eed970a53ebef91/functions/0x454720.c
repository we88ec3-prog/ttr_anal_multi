
undefined4 * FUN_00454720(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091e5a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00754880(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  *param_1 = FoxUI::FXUIContentButton::vftable;
  FUN_0077b520(param_1 + 0x57);
  *(undefined1 *)(param_1 + 0x56) = 1;
  param_1[0x92] = 0;
  *param_1 = FUI::CBuffRadioBox::vftable;
  param_1[0x93] = 0;
  ExceptionList = local_10;
  return param_1;
}

