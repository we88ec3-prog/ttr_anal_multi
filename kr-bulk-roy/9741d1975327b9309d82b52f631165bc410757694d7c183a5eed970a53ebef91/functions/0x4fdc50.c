
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004fdc50(int param_1)

{
  int unaff_ESI;
  undefined2 local_a;
  
  if (unaff_ESI != 0) {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_a = 0x46;
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_a,6);
    }
    *(undefined4 *)(param_1 + 0x5eac) = 1;
    return;
  }
  FUN_006edb60(&DAT_00c0d8d4);
  return;
}

