
void FUN_007e9e50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = IS3D::CItemBaseNode::vftable;
  if (in_ECX[10] != 0) {
    FUN_00440a80();
    FUN_0089120c(in_ECX[10]);
  }
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

