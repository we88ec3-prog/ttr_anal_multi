
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00489c60(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  if ((_DAT_00fd8c24 & 1) == 0) {
    _DAT_00fd8c24 = _DAT_00fd8c24 | 1;
    iVar2 = 0x1f;
    puVar1 = &DAT_00fd8c30;
    do {
      puVar1[-2] = 0;
      puVar1[-1] = 0;
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1 = puVar1 + 5;
      iVar2 = iVar2 + -1;
    } while (-1 < iVar2);
    _atexit((_func_4879 *)&DAT_00bcdce0);
  }
  return &DAT_00fd8c28;
}

