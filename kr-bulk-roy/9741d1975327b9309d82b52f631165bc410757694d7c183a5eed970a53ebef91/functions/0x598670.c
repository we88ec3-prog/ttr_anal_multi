
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00598670(void)

{
  if ((_DAT_00fe2c68 & 1) == 0) {
    _DAT_00fe2c68 = _DAT_00fe2c68 | 1;
    DAT_00fe2c6c = 0;
    _atexit((_func_4879 *)&DAT_00bcf450);
  }
  return &DAT_00fe2c6c;
}

