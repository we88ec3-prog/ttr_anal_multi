
void FUN_007f2910(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = IS3D::CEffectElement::vftable;
  if (in_ECX[0x1d] != 0) {
    FUN_0089120c(in_ECX[0x1d]);
    in_ECX[0x1d] = 0;
  }
  if (in_ECX[0x1e] != 0) {
    FUN_0089120c(in_ECX[0x1e]);
    in_ECX[0x1e] = 0;
  }
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

