
void FUN_00427b50(void)

{
  undefined4 *unaff_ESI;
  
  FUN_004285e0();
  unaff_ESI[0x44] = 0;
  unaff_ESI[0x45] = 0;
  *unaff_ESI = FUI::CDuelGroupListPanel::vftable;
  unaff_ESI[0x46] = 0;
  unaff_ESI[0x47] = 0;
  unaff_ESI[0x48] = 0;
  unaff_ESI[0x49] = 0;
  unaff_ESI[0x4a] = 0;
  unaff_ESI[0x4b] = 0;
  *(undefined1 *)(unaff_ESI + 0x4d) = 0;
  unaff_ESI[0x4c] = 99;
  return;
}

