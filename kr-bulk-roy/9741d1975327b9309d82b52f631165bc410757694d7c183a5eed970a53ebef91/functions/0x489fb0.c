
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00489fb0(void)

{
  if ((_DAT_00fdf3c0 & 1) == 0) {
    _DAT_00fdf3c0 = _DAT_00fdf3c0 | 1;
    DAT_00fdf3c4 = 0;
    _atexit((_func_4879 *)&DAT_00bcdf50);
  }
  return &DAT_00fdf3c4;
}

