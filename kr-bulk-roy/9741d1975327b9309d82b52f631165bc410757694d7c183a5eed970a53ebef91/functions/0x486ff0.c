
undefined4 * FUN_00486ff0(byte param_1)

{
  undefined4 *in_ECX;
  
  if ((param_1 & 2) != 0) {
    _eh_vector_destructor_iterator_(in_ECX,0x15c,in_ECX[-1],FUN_0075eb70);
    if ((param_1 & 1) != 0) {
      FUN_00891d3d(in_ECX + -1);
    }
    return in_ECX + -1;
  }
  *in_ECX = FoxUI::FXUIStatic::vftable;
  FUN_00754980();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return in_ECX;
}

