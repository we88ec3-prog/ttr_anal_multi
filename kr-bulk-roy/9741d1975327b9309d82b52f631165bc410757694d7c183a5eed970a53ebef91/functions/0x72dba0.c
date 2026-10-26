
void FUN_0072dba0(byte param_1)

{
  undefined4 *in_ECX;
  
  if (0xf < (uint)in_ECX[0x11]) {
    FUN_0089120c(in_ECX[0xc]);
  }
  in_ECX[0x11] = 0xf;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0xc) = 0;
  if (0xf < (uint)in_ECX[10]) {
    FUN_0089120c(in_ECX[5]);
  }
  in_ECX[9] = 0;
  in_ECX[10] = 0xf;
  *(undefined1 *)(in_ECX + 5) = 0;
  *in_ECX = TiXmlBase::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

