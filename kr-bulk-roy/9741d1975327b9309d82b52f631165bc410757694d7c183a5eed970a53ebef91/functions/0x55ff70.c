
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0055ff70(void)

{
  if ((_DAT_00fe38cc & 1) == 0) {
    _DAT_00fe38cc = _DAT_00fe38cc | 1;
    _DAT_00fe36e4 = 0x400;
    _DAT_00fe36e8 = 0x300;
    _DAT_00fe36ec = 0;
    _atexit((_func_4879 *)&DAT_00bcf2d0);
  }
  return &DAT_00fe36e0;
}

