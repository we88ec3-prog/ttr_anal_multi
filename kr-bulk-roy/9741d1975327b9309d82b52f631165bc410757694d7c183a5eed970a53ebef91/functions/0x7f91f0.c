
void FUN_007f91f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = IS3D::CEnvParticle::vftable;
  if (0xf < (uint)in_ECX[7]) {
    FUN_0089120c(in_ECX[2]);
  }
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  *in_ECX = IS3D::IRenderable::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

