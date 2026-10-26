
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0048a930(void)

{
  if ((_DAT_00fc1ca8 & 1) == 0) {
    _DAT_00fc1ca8 = _DAT_00fc1ca8 | 1;
    DAT_00fc1cac = 0;
    DAT_00fc1cb0 = 0;
    _DAT_00fc1cb4 = 0;
    _atexit((_func_4879 *)&LAB_00bce5a0);
  }
  return &DAT_00fc1cac;
}

