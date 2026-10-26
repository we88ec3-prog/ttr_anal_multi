
void FUN_005a7000(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = FUI::CServerSelectDialog::vftable;
  if (unaff_ESI[0x3f] != 0) {
    FUN_005aa000(unaff_ESI[0x40]);
    FUN_0089120c(unaff_ESI[0x3f]);
  }
  unaff_ESI[0x3f] = 0;
  unaff_ESI[0x40] = 0;
  unaff_ESI[0x41] = 0;
  *unaff_ESI = FoxUI::FXUIWindowSimple::vftable;
  FUN_00756590();
  return;
}

