
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_006f1d70(void)

{
  if ((_DAT_00fe31c8 & 1) == 0) {
    _DAT_00fe31c8 = _DAT_00fe31c8 | 1;
    _DAT_00fe31cc = CIMM::vftable;
    DAT_00fe31d0 = 0;
    _atexit((_func_4879 *)&LAB_00bd0740);
  }
  return &DAT_00fe31cc;
}

