
void FUN_00540460(byte param_1)

{
  undefined4 *in_ECX;
  
  if (in_ECX[0x11] != 0) {
    FUN_0049bf30();
    FUN_0089120c(in_ECX[0x11]);
  }
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  *in_ECX = FlyingObject::CDefFlyingObject::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

