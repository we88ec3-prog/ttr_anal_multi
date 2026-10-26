
void FUN_007d2940(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = IS3D::CItem::vftable;
  if (in_ECX[6] != 0) {
    FUN_0089120c(in_ECX[6]);
  }
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  *in_ECX = IS3D::IRenderable::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

