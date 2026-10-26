
void FUN_0046c6e0(byte param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009179e8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::COnScreenKeyBoardDialog::vftable;
  local_8 = 0;
  _eh_vector_destructor_iterator_(in_ECX + 0x76,0x10,0x31,FUN_005f5d10);
  local_8 = 0xffffffff;
  *in_ECX = FoxUI::FXUIWindowClose::vftable;
  FUN_00756590(uVar1);
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  ExceptionList = local_10;
  return;
}

