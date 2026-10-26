
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00494750(undefined4 param_1)

{
  if ((_DAT_00fdf6e0 & 1) == 0) {
    _DAT_00fdf6e0 = _DAT_00fdf6e0 | 1;
    _atexit((_func_4879 *)&DAT_00bcdd00);
  }
  FUN_004d2e40(param_1);
  return;
}

