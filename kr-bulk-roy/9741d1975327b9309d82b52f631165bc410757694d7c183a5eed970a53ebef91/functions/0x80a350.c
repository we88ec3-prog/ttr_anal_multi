
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0080a350(void)

{
  if ((_DAT_00fe33fc & 1) == 0) {
    _DAT_00fe33fc = _DAT_00fe33fc | 1;
    DAT_00fe3400 = 0;
    _DAT_00fe3404 = 0;
    _DAT_00fe3408 = 0;
    _DAT_00fe3410 = 4;
    _atexit((_func_4879 *)&LAB_00bd0c00);
  }
  return &DAT_00fe3400;
}

