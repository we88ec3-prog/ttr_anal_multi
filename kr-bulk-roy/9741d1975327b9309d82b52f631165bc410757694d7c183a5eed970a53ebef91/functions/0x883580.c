
void FUN_00883580(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = std::
            time_get<unsigned_short,std::istreambuf_iterator<unsigned_short,std::char_traits<unsigned_short>_>_>
            ::vftable;
  FUN_0088d8e2();
  *in_ECX = std::locale::facet::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

