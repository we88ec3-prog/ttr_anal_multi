
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0048a3d0(void)

{
  if ((_DAT_00fd94dc & 1) == 0) {
    _DAT_00fd94dc = _DAT_00fd94dc | 1;
    FUN_004f10f0();
    _atexit((_func_4879 *)&LAB_00bce260);
  }
  return &DAT_00fd94e0;
}

