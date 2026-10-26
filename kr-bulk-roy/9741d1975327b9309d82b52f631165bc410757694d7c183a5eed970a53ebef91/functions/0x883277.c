
void FUN_00883277(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = std::_Mpunct<wchar_t>::vftable;
  Tidy();
  *in_ECX = std::locale::facet::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

