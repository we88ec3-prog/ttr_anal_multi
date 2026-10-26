
void FUN_006de2a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = std::ctype<char>::vftable;
  if ((int)in_ECX[5] < 1) {
    if ((int)in_ECX[5] < 0) {
      FUN_00891d3d(in_ECX[4]);
    }
  }
  else {
    _free((void *)in_ECX[4]);
  }
  *in_ECX = std::locale::facet::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

