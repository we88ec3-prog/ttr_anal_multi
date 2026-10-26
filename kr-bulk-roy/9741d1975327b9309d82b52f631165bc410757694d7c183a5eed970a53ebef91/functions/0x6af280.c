
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006af280(int param_1)

{
  undefined2 in_CX;
  
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&stack0xfffffffa,2,CONCAT22(0x65,in_CX));
  }
  (**(code **)(**(int **)(param_1 + 0x11c) + 0x90))(0);
  return;
}

