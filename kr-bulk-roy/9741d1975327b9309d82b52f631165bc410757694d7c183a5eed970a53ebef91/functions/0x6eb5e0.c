
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_006eb5e0(void)

{
  if ((_DAT_00fe4b14 & 1) == 0) {
    _DAT_00fe4b14 = _DAT_00fe4b14 | 1;
    DAT_00fe36b0 = 0;
    _DAT_00fe36b4 = 0;
    _DAT_00fe36b8 = 0;
    DAT_00fe36bc = 0;
    _DAT_00fe36c0 = 0;
    _DAT_00fe36c4 = 0;
    DAT_00fe36c8 = 0;
    _DAT_00fe36cc = 0;
    _DAT_00fe36d0 = 0;
    _atexit((_func_4879 *)&LAB_00bd0720);
  }
  return &DAT_00fe36b0;
}

