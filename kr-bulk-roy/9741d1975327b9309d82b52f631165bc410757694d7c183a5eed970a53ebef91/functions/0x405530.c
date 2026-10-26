
void FUN_00405530(void)

{
  undefined4 *unaff_ESI;
  
  FUN_007564e0();
  unaff_ESI[0x3b] = 0;
  *(undefined1 *)(unaff_ESI + 0x3d) = 0;
  unaff_ESI[0x3e] = 0;
  unaff_ESI[0x93] = 0;
  unaff_ESI[0x94] = 0;
  unaff_ESI[0x9d] = 0;
  *(undefined1 *)(unaff_ESI + 0x3c) = 1;
  *unaff_ESI = FUI::CAttendanceEventWnd::vftable;
  unaff_ESI[0x95] = 0;
  unaff_ESI[0x96] = 0;
  unaff_ESI[0x97] = 0;
  unaff_ESI[0x98] = 0;
  unaff_ESI[0x99] = 0;
  unaff_ESI[0x9a] = 0;
  unaff_ESI[0x9b] = 0;
  *(undefined1 *)(unaff_ESI + 0x9c) = 0;
  return;
}

