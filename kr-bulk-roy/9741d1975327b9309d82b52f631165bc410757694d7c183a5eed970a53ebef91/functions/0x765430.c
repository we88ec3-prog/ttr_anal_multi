
void FUN_00765430(void)

{
  undefined4 *in_ECX;
  
  FUN_00754880();
  *in_ECX = FoxUI::FXUIToolTip::vftable;
  *(undefined1 *)(in_ECX + 0x56) = 1;
  return;
}

