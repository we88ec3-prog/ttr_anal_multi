
void FUN_00765a60(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00919086;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FoxUI::FXUITextBox::vftable;
  local_8 = 1;
  FUN_00765af0(uVar1);
  if (in_ECX[0x44] != 0) {
    FUN_0089120c(in_ECX[0x44]);
  }
  in_ECX[0x44] = 0;
  in_ECX[0x45] = 0;
  in_ECX[0x46] = 0;
  local_8 = 0xffffffff;
  FUN_00769220();
  ExceptionList = local_10;
  return;
}

