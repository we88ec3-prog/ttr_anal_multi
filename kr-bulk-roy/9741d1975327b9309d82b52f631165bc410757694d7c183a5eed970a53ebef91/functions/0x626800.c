
void FUN_00626800(void)

{
  undefined4 *unaff_ESI;
  
  FUN_007564e0();
  unaff_ESI[0x20] = 0;
  unaff_ESI[0x3b] = 0;
  unaff_ESI[0x3c] = 0;
  unaff_ESI[0x3e] = 0;
  unaff_ESI[0x3f] = 0;
  unaff_ESI[0x40] = 0;
  unaff_ESI[0x41] = 0;
  unaff_ESI[0x42] = 0;
  unaff_ESI[0x3d] = 0x10101;
  *unaff_ESI = FUI::CKeyOptionDialog::vftable;
  unaff_ESI[0x43] = 0;
  unaff_ESI[0x44] = 0;
  unaff_ESI[0x45] = 0;
  unaff_ESI[0x46] = 0;
  unaff_ESI[0x47] = 0;
  return;
}

