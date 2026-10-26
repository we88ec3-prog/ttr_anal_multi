
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005646a0(void)

{
  if ((_DAT_00fd2cf0 & 1) == 0) {
    _DAT_00fd2cf0 = _DAT_00fd2cf0 | 1;
    FUN_00738090();
    _atexit((_func_4879 *)&DAT_00bce680);
  }
  FUN_00738100();
  return;
}

