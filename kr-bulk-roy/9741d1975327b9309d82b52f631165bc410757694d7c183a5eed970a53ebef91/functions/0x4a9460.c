
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a9460(undefined4 param_1,undefined4 param_2,undefined4 param_3)

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
  FUN_00544940(param_1,param_2,param_3);
  return;
}

