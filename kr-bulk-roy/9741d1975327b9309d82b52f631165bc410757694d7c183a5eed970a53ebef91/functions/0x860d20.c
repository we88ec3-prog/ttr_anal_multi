
void FUN_00860d20(void)

{
  undefined4 *puVar1;
  void *_Dst;
  undefined4 *unaff_ESI;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)unaff_ESI[0xd];
  puVar2 = (undefined4 *)unaff_ESI[0xc];
  *unaff_ESI = gbTexImageController::vftable;
  for (; puVar2 != puVar1; puVar2 = puVar2 + 1) {
    FUN_0089120c(*puVar2);
  }
  _Dst = (void *)unaff_ESI[0xc];
  if (_Dst != (void *)unaff_ESI[0xd]) {
    FID_conflict__memcpy(_Dst,(void *)unaff_ESI[0xd],0);
    unaff_ESI[0xd] = _Dst;
  }
  if (unaff_ESI[0xc] != 0) {
    FUN_0089120c(unaff_ESI[0xc]);
  }
  unaff_ESI[0xc] = 0;
  unaff_ESI[0xd] = 0;
  unaff_ESI[0xe] = 0;
  *unaff_ESI = gbBase::vftable;
  if (0xf < (uint)unaff_ESI[7]) {
    FUN_0089120c(unaff_ESI[2]);
  }
  unaff_ESI[6] = 0;
  unaff_ESI[7] = 0xf;
  *(undefined1 *)(unaff_ESI + 2) = 0;
  *unaff_ESI = gbRefCount::vftable;
  return;
}

