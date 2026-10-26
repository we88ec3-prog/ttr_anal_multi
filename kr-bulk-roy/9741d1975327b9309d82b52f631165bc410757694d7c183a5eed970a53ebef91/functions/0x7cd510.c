
void FUN_007cd510(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = IS3D::CSimpleObject::vftable;
  if (in_ECX[9] != 0) {
    FUN_0089120c(in_ECX[9]);
  }
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  if (0xf < (uint)in_ECX[6]) {
    FUN_0089120c(in_ECX[1]);
  }
  in_ECX[6] = 0xf;
  in_ECX[5] = 0;
  *(undefined1 *)(in_ECX + 1) = 0;
  *in_ECX = IS3D::IRenderable::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

