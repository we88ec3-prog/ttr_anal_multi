
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a1400(void)

{
  if ((_DAT_00fdf3c0 & 1) == 0) {
    _DAT_00fdf3c0 = _DAT_00fdf3c0 | 1;
    DAT_00fdf3c4 = 0;
    _atexit((_func_4879 *)&DAT_00bcdf50);
  }
  FUN_0056cd10();
  return;
}

