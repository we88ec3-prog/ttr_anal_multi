
void FUN_00802260(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = IS3D::CQuadPatchParticle::vftable;
  if (in_ECX[0x3a] != 0) {
    FUN_00891d3d(in_ECX[0x3a]);
    in_ECX[0x3a] = 0;
  }
  FUN_007f2730();
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

