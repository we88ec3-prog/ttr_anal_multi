
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b3990(void)

{
  int in_ECX;
  undefined4 local_8;
  
  *(undefined1 *)(in_ECX + 0x13c) = 0;
  *(undefined1 *)(in_ECX + 0x15c) = 0;
  *(undefined1 *)(in_ECX + 0x154) = 0;
  *(undefined4 *)(in_ECX + 0x138) = 0x3f800000;
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_8 = 0x34;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_8,4);
  }
  return;
}

