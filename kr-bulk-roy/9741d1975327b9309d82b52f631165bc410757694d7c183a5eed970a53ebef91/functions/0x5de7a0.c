
undefined4 * FUN_005de7a0(byte param_1)

{
  undefined4 *in_ECX;
  
  if ((param_1 & 2) != 0) {
    _eh_vector_destructor_iterator_(in_ECX,0x298,in_ECX[-1],(_func_void_void_ptr *)&LAB_005de790);
    if ((param_1 & 1) != 0) {
      FUN_00891d3d(in_ECX + -1);
    }
    return in_ECX + -1;
  }
  *in_ECX = FUI::CItemSlotShopConsumption3::vftable;
  FUN_005d6e90();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return in_ECX;
}

