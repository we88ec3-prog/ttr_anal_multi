
void FUN_005d5a00(void)

{
  undefined4 *in_ECX;
  
  FUN_0075bb00();
  *in_ECX = FUI::CExpBar::vftable;
  in_ECX[0x3c] = 7;
  in_ECX[0x3b] = 0;
  *(undefined2 *)(in_ECX + 0x37) = 0;
  return;
}

