
void FUN_006897f0(byte param_1)

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
  *in_ECX = FUI::CQuantityDialog::vftable;
  local_8 = 0;
  if ((undefined4 *)in_ECX[0x48] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x48])(1,uVar1);
    in_ECX[0x48] = 0;
  }
  local_8 = 0xffffffff;
  *in_ECX = FoxUI::FXUIWindowClose::vftable;
  FUN_00756590();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  ExceptionList = local_10;
  return;
}

