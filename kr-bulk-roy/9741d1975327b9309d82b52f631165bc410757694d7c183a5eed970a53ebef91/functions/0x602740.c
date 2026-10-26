
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00602740(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  _param_1 = CONCAT11(param_2,param_1);
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  FUN_004a37b0(CONCAT12(param_3,_param_1));
  return;
}

