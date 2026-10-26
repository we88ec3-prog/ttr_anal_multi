
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00474e20(void)

{
  if ((_DAT_00fc0e10 & 1) == 0) {
    _DAT_00fc0e10 = _DAT_00fc0e10 | 1;
    DAT_00fc0e14 = 0;
    _DAT_00fc0e18 = 0;
    _DAT_00fc0e1c = 0;
    DAT_00fc0e24 = 0;
    _DAT_00fc0e28 = 0;
    _DAT_00fc0e2c = 0;
    _atexit((_func_4879 *)&LAB_00bcdaa0);
  }
  return &DAT_00fc0e14;
}

