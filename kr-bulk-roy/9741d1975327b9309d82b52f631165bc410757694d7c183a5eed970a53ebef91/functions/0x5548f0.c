
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_005548f0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092aff1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00555bd0(DAT_00d61f20 ^ (uint)&stack0xfffffffc,&DAT_00fc1900);
  DAT_00fc1910 = 0;
  DAT_00fc1914 = 0;
  _DAT_00fc1918 = 0;
  DAT_00fc1934 = 0xf;
  _DAT_00fc1930 = 0;
  DAT_00fc1920._0_1_ = 0;
  DAT_00fc1950 = 0xf;
  _DAT_00fc194c = 0;
  DAT_00fc193c._0_1_ = 0;
  DAT_00fc196c = 0xf;
  _DAT_00fc1968 = 0;
  DAT_00fc1958._0_1_ = 0;
  local_8 = 4;
  _DAT_00fc1974 = 0;
  _DAT_00fc1978 = 0;
  DAT_00fc1984 = 0;
  _DAT_00fc19e8 = 0;
  _DAT_00fc19ec = 0;
  _DAT_00fc19f0 = 0;
  FUN_00554fc0();
  ExceptionList = local_10;
  return &DAT_00fc1900;
}

