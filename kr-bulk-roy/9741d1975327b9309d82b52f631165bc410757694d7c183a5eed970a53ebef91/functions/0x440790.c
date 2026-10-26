
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00440790(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0x52) {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    FUN_004a3360(param_2);
    return;
  }
  if (*(int *)(in_ECX + 8) == 0x54) {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    FUN_004a31b0(param_2);
    return;
  }
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  FUN_004a31b0(param_2);
  return;
}

