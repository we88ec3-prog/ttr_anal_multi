
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ff1a0(void)

{
  int in_EAX;
  undefined1 local_7 [3];
  
  if (*(int *)(in_EAX + 0x5eac) != 0) {
    *(undefined4 *)(in_EAX + 0x623c) = 0;
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,local_7,3);
    }
  }
  return;
}

