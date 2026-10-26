
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e0c40(void)

{
  int unaff_ESI;
  undefined2 local_c;
  undefined1 local_a;
  undefined1 local_9;
  undefined4 local_8;
  
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_a = *(undefined1 *)(unaff_ESI + 0x298);
  local_9 = *(undefined1 *)(unaff_ESI + 0x29c);
  local_c = 0xbd;
  local_8 = 0;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_c,8);
  }
  (**(code **)(**(int **)(unaff_ESI + 0x2a4) + 0x90))(1);
  return;
}

