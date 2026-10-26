
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0068b1e0(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0xdc) == 2) {
    if ((_DAT_00fdf6e0 & 1) == 0) {
      _DAT_00fdf6e0 = _DAT_00fdf6e0 | 1;
      _atexit((_func_4879 *)&DAT_00bcdd00);
    }
    uVar1 = FUN_004d2da0(*(undefined4 *)(unaff_ESI + 0xe0));
    return uVar1;
  }
  if (*(int *)(unaff_ESI + 0xdc) == 3) {
    if ((_DAT_00fdf6e0 & 1) == 0) {
      _DAT_00fdf6e0 = _DAT_00fdf6e0 | 1;
      _atexit((_func_4879 *)&DAT_00bcdd00);
    }
    uVar1 = FUN_004d2cc0(*(undefined4 *)(unaff_ESI + 0xe4));
    return uVar1;
  }
  return 0;
}

