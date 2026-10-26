
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0048a600(void)

{
  if ((_DAT_00fd8c04 & 1) == 0) {
    _DAT_00fd8c04 = _DAT_00fd8c04 | 1;
    DAT_00fd8c1c = 7;
    DAT_00fd8c18 = 0;
    DAT_00fd8c08._0_2_ = 0;
    _atexit((_func_4879 *)&LAB_00bce360);
  }
  return &DAT_00fd8c08;
}

