
void FUN_00587400(void)

{
  undefined4 *in_ECX;
  
  FUN_007564e0();
  in_ECX[0x3b] = 0;
  *(undefined1 *)(in_ECX + 0x3c) = 0;
  *in_ECX = FUI::CMsgBoxYesNoNotKey::vftable;
  return;
}

