
void FUN_00409170(void)

{
  undefined4 *in_ECX;
  
  FUN_005d6dd0();
  in_ECX[0xa6] = 0xffffffff;
  in_ECX[0xa7] = 0xffffffff;
  *in_ECX = FUI::CAvatarRecycleSlot::vftable;
  in_ECX[0xa8] = 0;
  return;
}

