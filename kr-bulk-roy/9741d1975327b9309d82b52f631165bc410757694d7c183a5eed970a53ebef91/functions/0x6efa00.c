
void FUN_006efa00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = std::numpunct<char>::vftable;
  FUN_00891d3d(in_ECX[2]);
  FUN_00891d3d(in_ECX[4]);
  FUN_00891d3d(in_ECX[5]);
  *in_ECX = std::locale::facet::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

