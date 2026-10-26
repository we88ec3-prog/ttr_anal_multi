
void FUN_005902f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = TiXmlDeclaration::vftable;
  if (0xf < (uint)in_ECX[0x24]) {
    FUN_0089120c(in_ECX[0x1f]);
  }
  in_ECX[0x24] = 0xf;
  in_ECX[0x23] = 0;
  *(undefined1 *)(in_ECX + 0x1f) = 0;
  if (0xf < (uint)in_ECX[0x1d]) {
    FUN_0089120c(in_ECX[0x18]);
  }
  in_ECX[0x1d] = 0xf;
  in_ECX[0x1c] = 0;
  *(undefined1 *)(in_ECX + 0x18) = 0;
  if (0xf < (uint)in_ECX[0x16]) {
    FUN_0089120c(in_ECX[0x11]);
  }
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0xf;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  FUN_0072e040();
  return;
}

