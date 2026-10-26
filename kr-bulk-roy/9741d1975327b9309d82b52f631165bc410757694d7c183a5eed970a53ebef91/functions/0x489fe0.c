
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00489fe0(void)

{
  if ((_DAT_00fd8f0c & 1) == 0) {
    _DAT_00fd8f0c = _DAT_00fd8f0c | 1;
    FUN_00559120();
    _atexit((_func_4879 *)&DAT_00bcdf60);
  }
  return &DAT_00fd8f10;
}

