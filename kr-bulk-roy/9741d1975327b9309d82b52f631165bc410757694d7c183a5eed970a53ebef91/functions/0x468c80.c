
void FUN_00468c80(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = FUI::CMultipleServerDialog::vftable;
  if (unaff_ESI[0x49] != 0) {
    FUN_0089120c(unaff_ESI[0x49]);
  }
  unaff_ESI[0x49] = 0;
  unaff_ESI[0x4a] = 0;
  unaff_ESI[0x4b] = 0;
  if (unaff_ESI[0x45] != 0) {
    FUN_0089120c(unaff_ESI[0x45]);
  }
  unaff_ESI[0x45] = 0;
  unaff_ESI[0x46] = 0;
  unaff_ESI[0x47] = 0;
  if (unaff_ESI[0x41] != 0) {
    FUN_0089120c(unaff_ESI[0x41]);
  }
  unaff_ESI[0x41] = 0;
  unaff_ESI[0x42] = 0;
  unaff_ESI[0x43] = 0;
  *unaff_ESI = FoxUI::FXUIWindowSimple::vftable;
  FUN_00756590();
  return;
}

