
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0053bc00(undefined4 param_1,undefined1 param_2)

{
  undefined2 local_c;
  undefined1 local_a;
  undefined4 local_9;
  
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_c = 0x54;
  local_9 = param_1;
  local_a = param_2;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_c,7);
  }
  return;
}

