
void FUN_00418cc0(void)

{
  undefined4 *unaff_ESI;
  
  FUN_007451f0();
  unaff_ESI[0x20] = 0;
  *unaff_ESI = FUI::CCashShopService::vftable;
  unaff_ESI[0x21] = 0;
  _memset(unaff_ESI + 0x22,0,0x2c);
  unaff_ESI[0x2f] = 0;
  unaff_ESI[0x30] = 0;
  unaff_ESI[0x31] = 0;
  unaff_ESI[0x32] = 0;
  return;
}

