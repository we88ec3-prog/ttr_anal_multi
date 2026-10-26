
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00671e60(void)

{
  if ((_DAT_00fe2ffc & 1) == 0) {
    _DAT_00fe2ffc = _DAT_00fe2ffc | 1;
    _DAT_00fe3000 = 1;
    _DAT_00fe3004 = 0;
    _atexit((_func_4879 *)&DAT_00bcfed0);
  }
  return &DAT_00fe3000;
}

