
void FUN_00444ed0(void)

{
  undefined4 *in_ECX;
  
  FUN_005d6dd0();
  *(undefined2 *)(in_ECX + 0xa6) = 0;
  in_ECX[0xa7] = 0;
  in_ECX[0xa8] = 0;
  in_ECX[0xa9] = 0;
  *in_ECX = FUI::CTiosSlot::vftable;
  return;
}

