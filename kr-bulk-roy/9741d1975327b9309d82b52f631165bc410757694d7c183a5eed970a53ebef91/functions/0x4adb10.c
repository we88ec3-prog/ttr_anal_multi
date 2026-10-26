
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004adb10(void)

{
  int *in_ECX;
  undefined4 *puVar1;
  
  if ((_DAT_00fb79ec & 1) == 0) {
    _DAT_00fb79ec = _DAT_00fb79ec | 1;
    DAT_00fb79f0 = CCheckPointMgr::vftable;
    DAT_00fb79f4 = (undefined4 *)0x0;
    DAT_00fb79f8 = (undefined4 *)0x0;
    DAT_00fb79fc = 0;
    DAT_00fb7a04 = 1;
    _atexit((_func_4879 *)&LAB_00bcd270);
  }
  puVar1 = DAT_00fb79f4;
  if (DAT_00fb79f4 != DAT_00fb79f8) {
    do {
      (**(code **)(*(int *)*puVar1 + 0x20))();
      puVar1 = puVar1 + 1;
    } while (puVar1 != DAT_00fb79f8);
  }
  (**(code **)(*in_ECX + 0x24))();
  return 0;
}

