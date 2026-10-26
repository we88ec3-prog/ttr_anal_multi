
ios_base * FUN_007a4b70(byte param_1)

{
  ios_base *piVar1;
  ios_base *in_ECX;
  
  piVar1 = in_ECX + -0x18;
  *(undefined ***)(in_ECX + *(int *)(*(int *)piVar1 + 4) + -0x18) =
       std::basic_iostream<char,std::char_traits<char>_>::vftable;
  *(undefined ***)(in_ECX + *(int *)(*(int *)(in_ECX + -8) + 4) + -8) =
       std::basic_ostream<char,std::char_traits<char>_>::vftable;
  *(undefined ***)(in_ECX + *(int *)(*(int *)(in_ECX + -0x18) + 4) + -0x18) =
       std::basic_istream<char,std::char_traits<char>_>::vftable;
  *(undefined ***)in_ECX = std::ios_base::vftable;
  std::ios_base::_Ios_base_dtor(in_ECX);
  if ((param_1 & 1) != 0) {
    FUN_0089120c(piVar1);
  }
  return piVar1;
}

