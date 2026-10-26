
void FUN_007f1650(undefined4 param_1)

{
  undefined4 in_EAX;
  undefined4 *in_ECX;
  
  FUN_007e9bf0(in_EAX);
  in_ECX[0x21] = IS3D::IRenderable::vftable;
  *in_ECX = IS3D::CEffectElementBasic::vftable;
  in_ECX[0x21] = IS3D::CEffectElementBasic::vftable;
  in_ECX[0x22] = param_1;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x28] = 0;
  in_ECX[0x29] = 0;
  in_ECX[0x2c] = 0x477fff00;
  in_ECX[0x2b] = 0;
  in_ECX[1] = 1;
  return;
}

