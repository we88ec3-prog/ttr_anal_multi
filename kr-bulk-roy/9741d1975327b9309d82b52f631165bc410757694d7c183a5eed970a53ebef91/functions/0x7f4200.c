
void FUN_007f4200(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = IS3D::CSkyBox::vftable;
  if (0xf < (uint)in_ECX[0xcd]) {
    FUN_0089120c(in_ECX[200]);
  }
  in_ECX[0xcd] = 0xf;
  in_ECX[0xcc] = 0;
  *(undefined1 *)(in_ECX + 200) = 0;
  *in_ECX = IS3D::IRenderable::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

