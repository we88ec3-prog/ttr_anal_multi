
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00423060(void)

{
  int in_ECX;
  float local_8;
  
  FUN_004adb10();
  if (*(int *)(in_ECX + 0xbd54) != 0) {
    local_8 = *(float *)(in_ECX + 0xbd58) - 0.0333333;
    *(float *)(in_ECX + 0xbd58) = local_8;
    if (local_8 < 0.0) {
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      local_8 = 6.86636e-44;
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,&local_8,4);
      }
      *(undefined4 *)(in_ECX + 0xbd54) = 0;
    }
  }
  return 0;
}

