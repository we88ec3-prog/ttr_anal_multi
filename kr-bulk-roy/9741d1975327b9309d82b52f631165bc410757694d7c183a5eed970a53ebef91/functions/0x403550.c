
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00403550(void)

{
  if ((_DAT_00f8d910 & 1) == 0) {
    _DAT_00f8d910 = _DAT_00f8d910 | 1;
    _atexit((_func_4879 *)&DAT_00bccc60);
  }
  return &DAT_00f8d914;
}

