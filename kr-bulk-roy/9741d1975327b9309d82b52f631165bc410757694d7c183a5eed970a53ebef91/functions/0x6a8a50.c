
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006a8a50(int param_1)

{
  int *in_ECX;
  undefined2 local_c;
  int local_a;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x40] + 0x20)) {
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      local_a = in_ECX[0x43];
      local_c = 0x7a;
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,&local_c,6);
      }
      (**(code **)(*in_ECX + 0xd4))();
      return;
    }
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x41] + 0x20)) {
      (**(code **)(*in_ECX + 0xd4))();
    }
  }
  return;
}

