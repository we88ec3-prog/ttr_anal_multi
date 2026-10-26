
ios_base * FUN_00431d70(byte param_1)

{
  ios_base *in_ECX;
  
  FUN_00431040();
  *(undefined ***)in_ECX = std::ios_base::vftable;
  std::ios_base::_Ios_base_dtor(in_ECX);
  if ((param_1 & 1) != 0) {
    FUN_0089120c(in_ECX + -0x60);
  }
  return in_ECX + -0x60;
}

