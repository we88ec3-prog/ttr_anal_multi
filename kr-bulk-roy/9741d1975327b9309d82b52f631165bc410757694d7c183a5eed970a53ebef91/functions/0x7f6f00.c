
void FUN_007f6f00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = IS3D::CFieldObjectCache::vftable;
  if (0xf < (uint)in_ECX[6]) {
    FUN_0089120c(in_ECX[1]);
  }
  in_ECX[6] = 0xf;
  in_ECX[5] = 0;
  *(undefined1 *)(in_ECX + 1) = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

