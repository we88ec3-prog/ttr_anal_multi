
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0046fee0(void)

{
  if ((_DAT_00fc0db0 & 1) == 0) {
    _DAT_00fc0db0 = _DAT_00fc0db0 | 1;
    DAT_00fc0db4 = 0;
    DAT_00fc0db8 = 0;
    DAT_00fc0dbc = 0;
    DAT_00fc0dc0 = 0;
    _atexit((_func_4879 *)&DAT_00bcd9e0);
  }
  return &DAT_00fc0db4;
}

