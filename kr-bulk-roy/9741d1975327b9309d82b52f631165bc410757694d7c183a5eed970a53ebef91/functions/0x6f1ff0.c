
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_006f1ff0(void)

{
  DAT_00fc1864 = 7;
  DAT_00fc1880 = 7;
  DAT_00fc189c = 7;
  DAT_00fc1888._0_2_ = 0;
  DAT_00fc1840 = 0;
  DAT_00fc1844 = 0;
  _DAT_00fc1848 = 0;
  _DAT_00fc1860 = 0;
  DAT_00fc1850._0_2_ = 0;
  _DAT_00fc187c = 0;
  DAT_00fc186c._0_2_ = 0;
  _DAT_00fc1898 = 0;
  DAT_00fc18a4 = 0;
  DAT_00fc18a8 = 0;
  DAT_00fc18ac = 0;
  _DAT_00fc18b8 = 0;
  DAT_00fc18cc = 0;
  if ((_DAT_00fe31c8 & 1) == 0) {
    _DAT_00fe31c8 = _DAT_00fe31c8 | 1;
    _DAT_00fe31cc = CIMM::vftable;
    DAT_00fe31d0 = 0;
    _atexit((_func_4879 *)&LAB_00bd0740);
  }
  FUN_006f42d0();
  return &DAT_00fc1840;
}

