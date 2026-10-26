
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ec750(undefined4 param_1,undefined4 param_2,char param_3)

{
  undefined2 local_10;
  undefined1 local_e;
  undefined4 local_d;
  undefined4 local_9;
  
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_e = param_3 == '\0';
  local_10 = 0xbbe;
  local_d = param_1;
  local_9 = param_2;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(2,&local_10,0xb);
  }
  return;
}

