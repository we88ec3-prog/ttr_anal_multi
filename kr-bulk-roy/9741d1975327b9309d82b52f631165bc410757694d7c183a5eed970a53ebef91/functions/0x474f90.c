
void FUN_00474f90(void)

{
  undefined4 *unaff_ESI;
  
  FUN_007564e0();
  *(undefined1 *)(unaff_ESI + 0x3c) = 1;
  unaff_ESI[0x47] = 1;
  *(undefined1 *)(unaff_ESI + 0x50) = 1;
  unaff_ESI[0x3b] = 0;
  *unaff_ESI = FUI::CPreviewCharView::vftable;
  unaff_ESI[0x3d] = 0;
  unaff_ESI[0x46] = 0;
  unaff_ESI[0x48] = 0;
  unaff_ESI[0x49] = 0;
  return;
}

