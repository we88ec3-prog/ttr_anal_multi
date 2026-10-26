
void FUN_007f8c00(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = IS3D::CSnow::vftable;
  if (unaff_ESI[0x32] != 0) {
    FUN_00891d3d(unaff_ESI[0x32]);
    unaff_ESI[0x32] = 0;
  }
  *unaff_ESI = IS3D::CEnvParticle::vftable;
  if (0xf < (uint)unaff_ESI[7]) {
    FUN_0089120c(unaff_ESI[2]);
  }
  unaff_ESI[7] = 0xf;
  unaff_ESI[6] = 0;
  *(undefined1 *)(unaff_ESI + 2) = 0;
  *unaff_ESI = IS3D::IRenderable::vftable;
  return;
}

