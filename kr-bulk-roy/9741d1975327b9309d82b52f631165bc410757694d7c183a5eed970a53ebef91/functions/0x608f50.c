
void FUN_00608f50(void)

{
  undefined4 *unaff_ESI;
  
  FUN_007564e0();
  unaff_ESI[0x3b] = 0;
  unaff_ESI[0x3d] = 0;
  unaff_ESI[0x3e] = 0;
  unaff_ESI[0x3f] = 0;
  unaff_ESI[0x40] = 0;
  *(undefined1 *)(unaff_ESI + 0x3c) = 1;
  *unaff_ESI = FUI::CItemOptionRegrantDlg::vftable;
  unaff_ESI[0x46] = 0;
  unaff_ESI[0x47] = 0;
  unaff_ESI[0x42] = 0xffffffff;
  unaff_ESI[0x43] = 0xffffffff;
  unaff_ESI[0x44] = 0xffffffff;
  unaff_ESI[0x45] = 0xffffffff;
  unaff_ESI[0x4c] = 0;
  unaff_ESI[0x4d] = 7;
  *(undefined2 *)(unaff_ESI + 0x48) = 0;
  unaff_ESI[0x4f] = 0xffffffff;
  unaff_ESI[0x50] = 0xffffffff;
  unaff_ESI[0x52] = 0;
  unaff_ESI[0x53] = 0;
  unaff_ESI[0x54] = 0;
  unaff_ESI[0x55] = 0;
  unaff_ESI[0x56] = 0xffffffff;
  unaff_ESI[0x58] = 0;
  unaff_ESI[0x59] = 0;
  return;
}

