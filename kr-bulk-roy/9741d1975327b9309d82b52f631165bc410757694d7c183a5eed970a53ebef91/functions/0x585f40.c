
void FUN_00585f40(void)

{
  undefined4 *unaff_ESI;
  
  FUN_007564e0();
  unaff_ESI[0x3b] = 0;
  *(undefined1 *)(unaff_ESI + 0x3c) = 0;
  unaff_ESI[0x3e] = 0;
  unaff_ESI[0x3f] = 0;
  unaff_ESI[0x40] = 0;
  *unaff_ESI = FUI::CMsgBoxWaitTimer::vftable;
  unaff_ESI[0x3d] = 5000;
  return;
}

