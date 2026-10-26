
void FUN_0079cb80(byte param_1)

{
  undefined4 *in_ECX;
  
  in_ECX[0xe] = IS3D::IRenderable::vftable;
  *in_ECX = IS3D::CCircleShadow::vftable;
  if (0xf < (uint)in_ECX[0xc]) {
    FUN_0089120c(in_ECX[7]);
  }
  in_ECX[0xc] = 0xf;
  in_ECX[0xb] = 0;
  *(undefined1 *)(in_ECX + 7) = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

