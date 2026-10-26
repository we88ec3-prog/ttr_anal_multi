
void FUN_005d7e30(void)

{
  undefined4 *in_ECX;
  
  FUN_005d6dd0();
  in_ECX[0xaa] = 0;
  in_ECX[0xab] = 0;
  in_ECX[0xad] = 0;
  *(undefined1 *)(in_ECX + 0xb0) = 0;
  in_ECX[0xa6] = 0;
  in_ECX[0xa7] = 0;
  in_ECX[0xa8] = 0;
  in_ECX[0xa9] = 0;
  in_ECX[0xaf] = 0;
  in_ECX[0xac] = 0;
  *in_ECX = FUI::CItemSlotShopTrade::vftable;
  in_ECX[0xae] = 0xffffffff;
  return;
}

