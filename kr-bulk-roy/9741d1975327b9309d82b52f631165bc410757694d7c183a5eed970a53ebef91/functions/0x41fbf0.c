
void FUN_0041fbf0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CContentsPointStatic::vftable;
  in_ECX[0xf] = 0;
  if (7 < (uint)in_ECX[0x5b]) {
    FUN_0089120c(in_ECX[0x56]);
  }
  in_ECX[0x5b] = 7;
  in_ECX[0x5a] = 0;
  *(undefined2 *)(in_ECX + 0x56) = 0;
  *in_ECX = FoxUI::FXUIStatic::vftable;
  FUN_00754980();
  return;
}

