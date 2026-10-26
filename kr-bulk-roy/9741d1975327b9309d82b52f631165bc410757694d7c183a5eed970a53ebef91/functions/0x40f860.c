
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0040f860(void)

{
  if ((_DAT_00fab244 & 1) == 0) {
    _DAT_00fab244 = _DAT_00fab244 | 1;
    DAT_00fab248 = 0;
    DAT_00fab24c = 0;
    _DAT_00fab250 = 0;
    DAT_00fab258 = 0;
    _DAT_00fab25c = 0;
    _DAT_00fab260 = 0;
    DAT_00fab268 = 0;
    DAT_00fab26c = 0;
    _DAT_00fab270 = 0;
    _atexit((_func_4879 *)&LAB_00bccee0);
  }
  return &DAT_00fab248;
}

