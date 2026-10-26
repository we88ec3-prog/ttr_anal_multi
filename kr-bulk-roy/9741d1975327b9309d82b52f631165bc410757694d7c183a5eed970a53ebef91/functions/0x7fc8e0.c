
void FUN_007fc8e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = IS3D::CItemNodeParticle::vftable;
  if (in_ECX[0x10] != 0) {
    FUN_0089120c(in_ECX[0x10]);
    in_ECX[0x10] = 0;
  }
  *in_ECX = IS3D::CItemNode::vftable;
  if (0xf < (uint)in_ECX[7]) {
    FUN_0089120c(in_ECX[2]);
  }
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

