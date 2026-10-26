
void FUN_00730100(void)

{
  ios_base *in_ECX;
  
  *(undefined ***)in_ECX = std::ios_base::vftable;
  std::ios_base::_Ios_base_dtor(in_ECX);
  return;
}

