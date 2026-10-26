
void FUN_00755270(void)

{
  undefined4 *in_ECX;
  
  FUN_007451f0();
  in_ECX[0x20] = 0x3f800000;
  in_ECX[0x21] = 0;
  in_ECX[0x22] = 0;
  *in_ECX = FoxUI::FXUIRDTarget::vftable;
  return;
}

