
void FUN_00755e20(void)

{
  undefined4 *in_ECX;
  
  FUN_007564e0();
  *in_ECX = FoxUI::FXUIWindowClose::vftable;
  in_ECX[0x3b] = 0;
  *(undefined1 *)(in_ECX + 0x3c) = 1;
  return;
}

