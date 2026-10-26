
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c30e0(int param_1)

{
  undefined2 local_c;
  undefined4 local_a;
  
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_a = *(undefined4 *)(param_1 + 0xb4);
  local_c = 0x8a;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_c,6);
  }
  return;
}

