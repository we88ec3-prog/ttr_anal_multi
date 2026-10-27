
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004b32e0(int param_1)

{
  if ((_DAT_00fb79ec & 1) == 0) {
    _DAT_00fb79ec = _DAT_00fb79ec | 1;
    DAT_00fb79f0 = CCheckPointMgr::vftable;
    DAT_00fb79f4 = 0;
    DAT_00fb79f8 = 0;
    DAT_00fb79fc = 0;
    DAT_00fb7a04 = 1;
    _atexit((_func_4879 *)&LAB_00bcd270);
  }
  FUN_00544940(*(undefined2 *)(param_1 + 2),*(undefined1 *)(param_1 + 4),
               *(undefined1 *)(param_1 + 5));
  return 0;
}

