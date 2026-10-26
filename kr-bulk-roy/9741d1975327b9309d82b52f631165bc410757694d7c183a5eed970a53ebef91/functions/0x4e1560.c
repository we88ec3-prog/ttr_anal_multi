
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004e1560(void)

{
  if ((_DAT_00fe1c4c & 1) == 0) {
    _DAT_00fe1c4c = _DAT_00fe1c4c | 1;
    FUN_004ff560();
    _atexit((_func_4879 *)&DAT_00bced40);
  }
  return &DAT_00fe1c50;
}

