
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064bda0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if ((_DAT_00fdf3c0 & 1) == 0) {
    _DAT_00fdf3c0 = _DAT_00fdf3c0 | 1;
    DAT_00fdf3c4 = 0;
    _atexit((_func_4879 *)&DAT_00bcdf50);
  }
  puVar1 = (undefined4 *)FUN_00891268(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = DAT_00fdf3c4;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[1] = 0x100;
    puVar1[2] = 0x100;
    *(undefined4 **)(in_ECX + 0xa8) = puVar1;
    return;
  }
  *(undefined4 *)(in_ECX + 0xa8) = 0;
  return;
}

