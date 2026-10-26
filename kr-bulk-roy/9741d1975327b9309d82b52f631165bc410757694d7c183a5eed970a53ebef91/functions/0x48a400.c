
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0048a400(void)

{
  if ((_DAT_00fd9274 & 1) == 0) {
    _DAT_00fd9274 = _DAT_00fd9274 | 1;
    DAT_00fd9278 = 0;
    _DAT_00fd927c = 0;
    _DAT_00fd9280 = 0;
    _atexit((_func_4879 *)&LAB_00bce2d0);
  }
  return &DAT_00fd9278;
}

