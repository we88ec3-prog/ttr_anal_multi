
void FUN_007f16d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = IS3D::CEffectElementBasic::vftable;
  in_ECX[0x21] = IS3D::CEffectElementBasic::vftable;
  if (in_ECX[0x27] != 0) {
    FUN_0089120c(in_ECX[0x27]);
  }
  in_ECX[0x27] = 0;
  in_ECX[0x28] = 0;
  in_ECX[0x29] = 0;
  if (in_ECX[0x23] != 0) {
    FUN_0089120c(in_ECX[0x23]);
  }
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x21] = IS3D::IRenderable::vftable;
  *in_ECX = IS3D::CEffectElement::vftable;
  if (in_ECX[0x1d] != 0) {
    FUN_0089120c(in_ECX[0x1d]);
    in_ECX[0x1d] = 0;
  }
  if (in_ECX[0x1e] != 0) {
    FUN_0089120c(in_ECX[0x1e]);
    in_ECX[0x1e] = 0;
  }
  return;
}

