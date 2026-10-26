
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ff140(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x623c) = 1;
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&stack0xfffffffa,2,CONCAT22(0x4f,(short)in_ECX));
  }
  return;
}

