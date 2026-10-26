
void FUN_005daa50(void)

{
  undefined4 *in_ECX;
  
  FUN_005d6dd0();
  in_ECX[0xa6] = 0;
  *in_ECX = FUI::CItemSlotQuickItem::vftable;
  in_ECX[0xb6] = 0;
  in_ECX[0xb7] = 7;
  *(undefined2 *)(in_ECX + 0xb2) = 0;
  in_ECX[0xae] = 0;
  in_ECX[0xaf] = 0;
  in_ECX[0xb0] = 0;
  in_ECX[0xb1] = 0;
  in_ECX[0xa9] = 0;
  in_ECX[0xab] = 0;
  in_ECX[0xad] = 0;
  in_ECX[0xaa] = 0;
  in_ECX[0xac] = 0;
  in_ECX[0xa8] = 0xffffffff;
  return;
}

