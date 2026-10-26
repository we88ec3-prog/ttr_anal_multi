
void FUN_0089118e(byte param_1)

{
  exception *in_ECX;
  
  *(undefined ***)in_ECX = std::exception::vftable;
  std::exception::_Tidy(in_ECX);
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

