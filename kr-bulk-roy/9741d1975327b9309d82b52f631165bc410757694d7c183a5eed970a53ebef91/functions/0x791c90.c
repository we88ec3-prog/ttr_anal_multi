
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00791c90(void)

{
  if (DAT_00fe320c == (undefined *)0x0) {
    if ((_DAT_00fe37e0 & 1) == 0) {
      _DAT_00fe37e0 = _DAT_00fe37e0 | 1;
      _DAT_00fe3530 = gbTCBInterpolator<float>::vftable;
      _atexit((_func_4879 *)&LAB_00bd09a0);
    }
    DAT_00fe320c = &DAT_00fe3530;
  }
  return;
}

