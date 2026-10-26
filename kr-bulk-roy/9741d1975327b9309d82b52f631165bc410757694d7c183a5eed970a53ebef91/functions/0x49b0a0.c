
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0049b0a0(void)

{
  if ((_DAT_00fd2cf0 & 1) == 0) {
    _DAT_00fd2cf0 = _DAT_00fd2cf0 | 1;
    FUN_00738090();
    _atexit((_func_4879 *)&DAT_00bce680);
  }
  return &DAT_00fd2bb8;
}

