
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00598640(void)

{
  if ((_DAT_00fe2c78 & 1) == 0) {
    _DAT_00fe2c78 = _DAT_00fe2c78 | 1;
    DAT_00fe2c7c = 0;
    _atexit((_func_4879 *)&DAT_00bcf440);
  }
  return &DAT_00fe2c7c;
}

