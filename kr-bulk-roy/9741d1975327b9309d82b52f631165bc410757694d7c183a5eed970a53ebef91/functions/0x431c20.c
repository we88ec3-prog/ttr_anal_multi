
void FUN_00431c20(byte param_1)

{
  ios_base *in_ECX;
  
  *(undefined ***)in_ECX = std::ios_base::vftable;
  std::ios_base::_Ios_base_dtor(in_ECX);
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

