
void FUN_00459210(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CItemCubeCoinSlot::vftable;
  if (7 < (uint)in_ECX[0xb3]) {
    FUN_0089120c(in_ECX[0xae]);
  }
  in_ECX[0xb3] = 7;
  in_ECX[0xb2] = 0;
  *(undefined2 *)(in_ECX + 0xae) = 0;
  FUN_005d6e90();
  return;
}

