
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ff480(undefined4 param_1)

{
  undefined2 local_a;
  undefined4 local_8;
  
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_a = 0x4e;
  local_8 = param_1;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_a,6);
  }
  return;
}

