
void FUN_00586d10(void)

{
  undefined4 *in_ECX;
  
  FUN_007564e0();
  in_ECX[0x3b] = 0;
  *(undefined1 *)(in_ECX + 0x3c) = 0;
  *in_ECX = FUI::CMsgBoxNo::vftable;
  return;
}

