
void FUN_005daad0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CItemSlotQuickItem::vftable;
  if (7 < (uint)in_ECX[0xb7]) {
    FUN_0089120c(in_ECX[0xb2]);
  }
  in_ECX[0xb7] = 7;
  in_ECX[0xb6] = 0;
  *(undefined2 *)(in_ECX + 0xb2) = 0;
  *in_ECX = FUI::CItemSlotQuantity::vftable;
  FUN_005d6e90();
  return;
}

