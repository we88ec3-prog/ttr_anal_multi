
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c93e0(void)

{
  int unaff_ESI;
  undefined2 local_10;
  undefined4 local_e;
  undefined4 local_a;
  
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_e = *(undefined4 *)(unaff_ESI + 0x11c);
  local_10 = 0xce;
  local_a = 1;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_10,10);
  }
  (**(code **)(**(int **)(unaff_ESI + 0xfc) + 0x90))(0);
  (**(code **)(**(int **)(unaff_ESI + 0xfc) + 200))();
  return;
}

