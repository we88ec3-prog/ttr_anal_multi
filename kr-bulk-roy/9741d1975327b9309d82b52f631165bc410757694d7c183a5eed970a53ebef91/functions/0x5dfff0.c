
void FUN_005dfff0(void)

{
  undefined4 *in_ECX;
  
  FUN_005d6dd0();
  *in_ECX = FUI::CItemSlotInfo::vftable;
  in_ECX[0xa7] = 0xffffffff;
  return;
}

