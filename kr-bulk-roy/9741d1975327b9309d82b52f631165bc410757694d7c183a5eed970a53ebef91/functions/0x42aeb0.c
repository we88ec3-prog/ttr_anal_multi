
void FUN_0042aeb0(void)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917c18;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00744320(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  *in_ECX = FoxUI::FXUIButton::vftable;
  FUN_0077b520(in_ECX + 0x2a);
  *(undefined1 *)(in_ECX + 0x29) = 1;
  *in_ECX = FoxUI::FXUIButtonResizeLT::vftable;
  ExceptionList = local_10;
  return;
}

