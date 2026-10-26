
void FUN_006deaa0(void)

{
  undefined4 in_ECX;
  undefined4 in_EDX;
  undefined4 *unaff_ESI;
  
  *(undefined8 *)(unaff_ESI + 6) = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[8] = 0;
  unaff_ESI[4] = 0;
  unaff_ESI[5] = 0;
  unaff_ESI[0xb] = 0;
  unaff_ESI[0xd] = 0;
  *unaff_ESI = CFramework::vftable;
  unaff_ESI[3] = 0xcf0000;
  unaff_ESI[9] = L"ISFramework";
  unaff_ESI[10] = L"Tartaros Rebirth";
  unaff_ESI[0xc] = 1;
  unaff_ESI[0xe] = in_ECX;
  unaff_ESI[0xf] = in_EDX;
  _memset(unaff_ESI + 0x10,0,0x100);
  return;
}

