
void FUN_005e0990(void)

{
  undefined4 *in_ECX;
  
  FUN_005d6dd0();
  in_ECX[0xa8] = 0;
  in_ECX[0xa9] = 0;
  *(undefined1 *)(in_ECX + 0xaa) = 0;
  in_ECX[0xa7] = 0xffffffff;
  *in_ECX = FUI::CItemSlotMyInfo::vftable;
  return;
}

