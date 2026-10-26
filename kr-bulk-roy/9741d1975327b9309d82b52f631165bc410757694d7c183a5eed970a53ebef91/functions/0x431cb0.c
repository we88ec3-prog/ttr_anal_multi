
ios_base * FUN_00431cb0(byte param_1)

{
  ios_base *piVar1;
  ios_base *in_ECX;
  
  piVar1 = in_ECX + -0x10;
  *(undefined ***)(in_ECX + *(int *)(*(int *)piVar1 + 4) + -0x10) =
       std::basic_istream<wchar_t,std::char_traits<wchar_t>_>::vftable;
  *(undefined ***)in_ECX = std::ios_base::vftable;
  std::ios_base::_Ios_base_dtor(in_ECX);
  if ((param_1 & 1) != 0) {
    FUN_0089120c(piVar1);
  }
  return piVar1;
}

