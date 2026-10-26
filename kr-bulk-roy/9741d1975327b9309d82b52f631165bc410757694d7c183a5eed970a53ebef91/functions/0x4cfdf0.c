
void FUN_004cfdf0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CDropItem::vftable;
  if (7 < (uint)in_ECX[0x4e]) {
    FUN_0089120c(in_ECX[0x49]);
  }
  in_ECX[0x4e] = 7;
  in_ECX[0x4d] = 0;
  *(undefined2 *)(in_ECX + 0x49) = 0;
  *in_ECX = CBasicObject::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

