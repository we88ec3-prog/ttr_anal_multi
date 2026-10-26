
void FUN_005d9830(void)

{
  undefined4 *in_ECX;
  
  FUN_005d6dd0();
  in_ECX[0xa7] = 0;
  in_ECX[0xa8] = 0;
  *in_ECX = FUI::CItemSlotShopStoneMerge::vftable;
  in_ECX[0xa6] = 0xffffffff;
  return;
}

