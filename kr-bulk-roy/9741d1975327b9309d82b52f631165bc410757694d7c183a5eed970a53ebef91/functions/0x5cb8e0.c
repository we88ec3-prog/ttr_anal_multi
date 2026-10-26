
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005cb8e0(void)

{
  if ((_DAT_00fc183c & 1) == 0) {
    _DAT_00fc183c = _DAT_00fc183c | 1;
    FUN_006f1ff0();
    DAT_00fc18d8 = 1;
    _atexit((_func_4879 *)&LAB_00bce3a0);
  }
  FUN_00402400(0,0xffffffff);
  DAT_00fc18a4 = 0;
  DAT_00fc18ac = 0;
  DAT_00fc18a8 = 0;
  FUN_00402400(0,0xffffffff);
  if ((_DAT_00fc183c & 1) == 0) {
    _DAT_00fc183c = _DAT_00fc183c | 1;
    FUN_006f1ff0();
    DAT_00fc18d8 = 1;
    _atexit((_func_4879 *)&LAB_00bce3a0);
  }
  _DAT_00fc1860 = 0;
  if (7 < DAT_00fc1864) {
    *DAT_00fc1850 = 0;
    return;
  }
  DAT_00fc1850 = (undefined2 *)((uint)DAT_00fc1850 & 0xffff0000);
  return;
}

