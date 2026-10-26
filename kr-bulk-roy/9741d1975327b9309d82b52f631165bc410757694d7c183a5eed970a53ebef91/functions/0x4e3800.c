
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e3800(undefined4 param_1,undefined4 param_2)

{
  if ((_DAT_00fe1c4c & 1) == 0) {
    _DAT_00fe1c4c = _DAT_00fe1c4c | 1;
    FUN_004ff560();
    _atexit((_func_4879 *)&DAT_00bced40);
  }
  FUN_004ff6a0(param_1,param_2);
  return;
}

