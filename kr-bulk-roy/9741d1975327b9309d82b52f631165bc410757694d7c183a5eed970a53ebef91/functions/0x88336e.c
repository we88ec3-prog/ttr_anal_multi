
void FUN_0088336e(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = std::time_get<wchar_t,std::istreambuf_iterator<wchar_t,std::char_traits<wchar_t>_>_>::
            vftable;
  FUN_0088d8e2();
  *in_ECX = std::locale::facet::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

