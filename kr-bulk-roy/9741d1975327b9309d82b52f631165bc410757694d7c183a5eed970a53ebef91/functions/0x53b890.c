
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0053b890(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  undefined2 local_c;
  undefined1 local_a;
  undefined1 local_9;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_c = 0x52;
  local_a = param_1;
  local_9 = 9;
  local_8 = param_2;
  local_7 = param_3;
  local_6 = param_4;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_c,7);
  }
  return;
}

