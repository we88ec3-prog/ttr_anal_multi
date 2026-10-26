
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00464f70(void)

{
  if ((_DAT_00fc0d5c & 1) == 0) {
    _DAT_00fc0d5c = _DAT_00fc0d5c | 1;
    DAT_00fc0d60 = 0;
    DAT_00fc0d64 = 0;
    _DAT_00fc0d68 = 0;
    _atexit((_func_4879 *)&LAB_00bcd8c0);
  }
  return &DAT_00fc0d60;
}

