
void FUN_0079c7a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = IS3D::CCircleShadow::vftable;
  if (0xf < (uint)in_ECX[0xc]) {
    FUN_0089120c(in_ECX[7]);
  }
  in_ECX[0xc] = 0xf;
  in_ECX[0xb] = 0;
  *(undefined1 *)(in_ECX + 7) = 0;
  return;
}

