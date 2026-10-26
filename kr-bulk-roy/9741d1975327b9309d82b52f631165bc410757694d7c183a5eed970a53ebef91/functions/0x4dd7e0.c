
void FUN_004dd7e0(void)

{
  void *_Dst;
  int iVar1;
  undefined4 *unaff_ESI;
  
  *unaff_ESI = CGameInfo::vftable;
  FUN_00797a00();
  _Dst = (void *)unaff_ESI[0x17ba];
  if (_Dst != (void *)unaff_ESI[0x17bb]) {
    FID_conflict__memcpy(_Dst,(void *)unaff_ESI[0x17bb],0);
    unaff_ESI[0x17bb] = _Dst;
  }
  iVar1 = unaff_ESI[0x17bf];
  if (iVar1 != 0) {
    FUN_0089120c(iVar1);
  }
  unaff_ESI[0x17bf] = 0;
  unaff_ESI[0x17c0] = 0;
  unaff_ESI[0x17c1] = 0;
  if (unaff_ESI[0x17ba] != 0) {
    FUN_0089120c(unaff_ESI[0x17ba]);
  }
  unaff_ESI[0x17ba] = 0;
  unaff_ESI[0x17bb] = 0;
  unaff_ESI[0x17bc] = 0;
  if (unaff_ESI[0x17b6] != 0) {
    FUN_0089120c(unaff_ESI[0x17b6]);
  }
  unaff_ESI[0x17b6] = 0;
  unaff_ESI[0x17b7] = 0;
  unaff_ESI[0x17b8] = 0;
  if (unaff_ESI[0x17b2] != 0) {
    FUN_0089120c(unaff_ESI[0x17b2]);
  }
  unaff_ESI[0x17b2] = 0;
  unaff_ESI[0x17b3] = 0;
  unaff_ESI[0x17b4] = 0;
  if (unaff_ESI[0x17ae] != 0) {
    FUN_0089120c(unaff_ESI[0x17ae]);
  }
  unaff_ESI[0x17ae] = 0;
  unaff_ESI[0x17af] = 0;
  unaff_ESI[0x17b0] = 0;
  *unaff_ESI = CPacketProcessor::vftable;
  return;
}

