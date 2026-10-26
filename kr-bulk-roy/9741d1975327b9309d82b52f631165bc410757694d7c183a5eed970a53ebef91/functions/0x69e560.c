
void FUN_0069e560(void)

{
  double dVar1;
  DWORD DVar2;
  undefined4 *unaff_ESI;
  
  FUN_007564e0();
  *unaff_ESI = FUI::CAuctionMyItemInside::vftable;
  unaff_ESI[0x3b] = 0;
  unaff_ESI[0x3c] = 0;
  unaff_ESI[0x3d] = 0;
  unaff_ESI[0x3e] = 0;
  unaff_ESI[0x3f] = 0;
  unaff_ESI[0x40] = 0;
  unaff_ESI[0x41] = 0;
  unaff_ESI[0x42] = 0;
  unaff_ESI[0x43] = 0;
  unaff_ESI[0x44] = 0;
  unaff_ESI[0x45] = 0;
  DVar2 = timeGetTime();
  dVar1 = (double)(int)DVar2;
  if ((int)DVar2 < 0) {
    dVar1 = dVar1 + 4294967296.0;
  }
  *(double *)(unaff_ESI + 0x46) = dVar1;
  DVar2 = timeGetTime();
  dVar1 = (double)(int)(DVar2 + 1000);
  if ((int)(DVar2 + 1000) < 0) {
    dVar1 = dVar1 + 4294967296.0;
  }
  *(double *)(unaff_ESI + 0x48) = dVar1;
  return;
}

