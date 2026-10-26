
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006daef0(void)

{
  DWORD DVar1;
  int *unaff_ESI;
  
  if (*unaff_ESI != 0) {
    if (unaff_ESI[0x14] == 0) {
      DVar1 = timeGetTime();
      unaff_ESI[0x14] = DVar1;
    }
    if ((_DAT_00fe6584 & 1) == 0) {
      _DAT_00fe6584 = _DAT_00fe6584 | 1;
      _DAT_00fe6580 = timeGetTime();
    }
    DVar1 = timeGetTime();
    if ((uint)(unaff_ESI[0x13] * 1000) < DVar1 - _DAT_00fe6580) {
      FUN_006daf70(unaff_ESI,DAT_00fe31a4 == 5);
      _DAT_00fe6580 = timeGetTime();
      if (DAT_00fe31a4 == 5) {
        DAT_00fe31a4 = 0;
      }
    }
  }
  return;
}

