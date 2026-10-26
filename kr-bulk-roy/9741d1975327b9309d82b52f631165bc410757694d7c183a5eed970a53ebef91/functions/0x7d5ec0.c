
void FUN_007d5ec0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = IS3D::CFaceInfo::vftable;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
    in_ECX[3] = 0;
  }
  in_ECX[4] = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

