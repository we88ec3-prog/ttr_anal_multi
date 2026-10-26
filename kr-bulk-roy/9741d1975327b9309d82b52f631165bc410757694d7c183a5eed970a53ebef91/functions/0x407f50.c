
void FUN_00407f50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = TiXmlDocument::vftable;
  if (0xf < (uint)in_ECX[0x18]) {
    FUN_0089120c(in_ECX[0x13]);
  }
  in_ECX[0x18] = 0xf;
  in_ECX[0x17] = 0;
  *(undefined1 *)(in_ECX + 0x13) = 0;
  FUN_0072e040();
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

