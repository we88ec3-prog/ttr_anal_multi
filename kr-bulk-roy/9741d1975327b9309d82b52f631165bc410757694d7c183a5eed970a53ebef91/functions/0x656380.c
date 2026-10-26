
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00656380(void)

{
  undefined2 in_CX;
  undefined2 local_8;
  undefined2 local_6;
  
  local_8 = in_CX;
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  _local_8 = CONCAT22(0x9f,local_8);
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_6,2);
  }
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  _local_8 = CONCAT22(local_6,0x19);
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_8,2);
  }
  return;
}

