
void FUN_005cc200(void)

{
  undefined4 *unaff_ESI;
  
  FUN_007564e0();
  *unaff_ESI = FUI::CBottomMenuFrame::vftable;
  unaff_ESI[0x3b] = 0;
  unaff_ESI[0x3d] = 0;
  unaff_ESI[0x3e] = 0;
  unaff_ESI[0x3f] = 0;
  unaff_ESI[0x40] = 0;
  unaff_ESI[0x41] = 0;
  unaff_ESI[0x42] = 0;
  _memset(unaff_ESI + 0x43,0,0x48);
  _memset(unaff_ESI + 0x55,0,0x30);
  unaff_ESI[0x66] = 7;
  unaff_ESI[0x65] = 0;
  *(undefined2 *)(unaff_ESI + 0x61) = 0;
  _memset(unaff_ESI + 0x68,0,0x48);
  _memset(unaff_ESI + 0x7a,0,0x78);
  unaff_ESI[0x98] = 0;
  unaff_ESI[0x99] = 0;
  _memset(unaff_ESI + 0x9a,0,0x30);
  _memset(unaff_ESI + 0xa6,0,0x48);
  unaff_ESI[0xb8] = 0;
  unaff_ESI[0xb9] = 0;
  unaff_ESI[0xba] = 0;
  unaff_ESI[0xbc] = 0;
  unaff_ESI[0xbe] = 0;
  unaff_ESI[0xbf] = 0;
  unaff_ESI[0xc0] = 0;
  unaff_ESI[0xc1] = 0;
  unaff_ESI[0xc2] = 0;
  unaff_ESI[0xbd] = 0xffffffff;
  unaff_ESI[0xc3] = 0;
  unaff_ESI[0xc4] = 0;
  unaff_ESI[0xc5] = 0;
  unaff_ESI[0xcb] = 7;
  unaff_ESI[0xca] = 0;
  *(undefined2 *)(unaff_ESI + 0xc6) = 0;
  unaff_ESI[0xcd] = 0;
  unaff_ESI[0xce] = 0;
  unaff_ESI[0xcf] = 0;
  unaff_ESI[0xd0] = 0;
  unaff_ESI[0xd1] = 0;
  unaff_ESI[0xd2] = 0;
  unaff_ESI[0xd3] = 0xbf800000;
  unaff_ESI[0xd4] = 0xffffffff;
  unaff_ESI[0xd5] = 0;
  unaff_ESI[0xd6] = 0;
  unaff_ESI[0xd7] = 0;
  unaff_ESI[0xd8] = 0;
  unaff_ESI[0xd9] = 0;
  unaff_ESI[0xda] = 0;
  unaff_ESI[0xdb] = 0xffffffff;
  unaff_ESI[0xdc] = 0xffffffff;
  unaff_ESI[0xdd] = 0;
  unaff_ESI[0xde] = 0;
  *(undefined2 *)(unaff_ESI + 0xdf) = 0;
  return;
}

