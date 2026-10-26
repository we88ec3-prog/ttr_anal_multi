
void FUN_00744320(void)

{
  undefined4 *in_ECX;
  
  FUN_007451f0();
  in_ECX[0x20] = 0x3f800000;
  in_ECX[0x21] = 0;
  in_ECX[0x22] = 0;
  *in_ECX = FoxUI::FXUIControl::vftable;
  in_ECX[0x25] = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x28] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0xbf69;
  return;
}

