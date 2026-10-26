
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004dda70(undefined1 param_1)

{
  undefined2 local_8;
  undefined1 local_6;
  undefined1 local_5;
  
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  _local_8 = CONCAT13(1,CONCAT12(param_1,0x7b));
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_8,4);
  }
  return;
}

