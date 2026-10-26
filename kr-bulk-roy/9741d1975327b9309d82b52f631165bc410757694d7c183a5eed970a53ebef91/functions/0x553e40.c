
void FUN_00553e40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FlyingObject::CFadeObject::vftable;
  if (0xf < (uint)in_ECX[0x17]) {
    FUN_0089120c(in_ECX[0x12]);
  }
  in_ECX[0x17] = 0xf;
  in_ECX[0x16] = 0;
  *(undefined1 *)(in_ECX + 0x12) = 0;
  *in_ECX = FlyingObject::CDefFlyingObject::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

