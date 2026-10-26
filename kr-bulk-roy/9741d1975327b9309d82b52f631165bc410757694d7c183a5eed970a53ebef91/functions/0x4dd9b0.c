
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004dd9b0(undefined2 param_1)

{
  undefined2 local_8;
  undefined2 local_6;
  
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  _local_8 = CONCAT22(param_1,100);
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_8,4);
  }
  return;
}

