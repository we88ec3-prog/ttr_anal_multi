
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_005984f0(void)

{
  if ((_DAT_00fe2c60 & 1) == 0) {
    _DAT_00fe2c60 = _DAT_00fe2c60 | 1;
    DAT_00fe2c64 = 0;
    _atexit((_func_4879 *)&DAT_00bcf430);
  }
  return &DAT_00fe2c64;
}

