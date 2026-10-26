
void FUN_00487a40(void)

{
  undefined4 *in_ECX;
  
  FUN_007564e0();
  in_ECX[0x3b] = 0;
  *(undefined1 *)(in_ECX + 0x3c) = 0;
  *in_ECX = FoxUI::FXUIMessageBoxNo::vftable;
  return;
}

