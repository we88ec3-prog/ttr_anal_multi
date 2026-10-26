
void FUN_00473640(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00919c68;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::CPracticeTalentListBoxItem::vftable;
  if (in_ECX[0x95] != 0) {
    FUN_0089120c(in_ECX[0x95],uVar1);
  }
  in_ECX[0x95] = 0;
  in_ECX[0x96] = 0;
  in_ECX[0x97] = 0;
  *in_ECX = FoxUI::FXUIContentButton::vftable;
  local_8 = 0;
  FUN_0077b5f0(in_ECX + 0x57);
  local_8 = 0xffffffff;
  FUN_00754980();
  ExceptionList = local_10;
  return;
}

