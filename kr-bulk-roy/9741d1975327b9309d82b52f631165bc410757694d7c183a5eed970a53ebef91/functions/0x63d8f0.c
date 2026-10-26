
void FUN_0063d8f0(void)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091d438;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00754880(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  *in_ECX = FoxUI::FXUIContentButton::vftable;
  FUN_0077b520(in_ECX + 0x57);
  *(undefined1 *)(in_ECX + 0x56) = 1;
  *in_ECX = FUI::CMSGBlackItem::vftable;
  ExceptionList = local_10;
  return;
}

