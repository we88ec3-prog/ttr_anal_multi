
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00791cd0(void)

{
  if (DAT_00fe3214 == (undefined *)0x0) {
    if ((_DAT_00fe37dc & 1) == 0) {
      _DAT_00fe37dc = _DAT_00fe37dc | 1;
      _DAT_00fe352c = gbTCBInterpolator<gbVec3<float>_>::vftable;
      _atexit((_func_4879 *)&LAB_00bd0990);
    }
    DAT_00fe3214 = &DAT_00fe352c;
  }
  return;
}

