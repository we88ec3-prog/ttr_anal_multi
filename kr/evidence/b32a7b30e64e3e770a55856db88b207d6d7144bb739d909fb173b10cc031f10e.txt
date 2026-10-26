
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004b24f0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if ((_DAT_00fb79ec & 1) == 0) {
    _DAT_00fb79ec = _DAT_00fb79ec | 1;
    DAT_00fb79f0 = CCheckPointMgr::vftable;
    DAT_00fb79f4 = 0;
    DAT_00fb79f8 = 0;
    DAT_00fb79fc = 0;
    DAT_00fb7a04 = 1;
    _atexit((_func_4879 *)&LAB_00bcd270);
  }
  FUN_005449a0(&DAT_00fb79f0);
  FUN_00544f50();
  uVar2 = *(undefined4 *)(param_1 + 2);
  uVar1 = FUN_0040f060(uVar2);
  FUN_004df510(uVar1,uVar2);
  return 0x100;
}

