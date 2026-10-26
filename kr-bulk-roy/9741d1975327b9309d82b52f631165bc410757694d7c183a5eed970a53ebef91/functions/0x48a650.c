
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0048a650(void)

{
  if ((_DAT_00fc183c & 1) == 0) {
    _DAT_00fc183c = _DAT_00fc183c | 1;
    FUN_006f1ff0();
    DAT_00fc18d8 = 1;
    _atexit((_func_4879 *)&LAB_00bce3a0);
  }
  return &DAT_00fc1840;
}

