
void FUN_00431200(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = std::ctype<wchar_t>::vftable;
  if (in_ECX[5] != 0) {
    _free((void *)in_ECX[4]);
  }
  *in_ECX = std::locale::facet::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

