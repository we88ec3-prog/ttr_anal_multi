
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00494710(void)

{
  if ((_DAT_00fd94dc & 1) == 0) {
    _DAT_00fd94dc = _DAT_00fd94dc | 1;
    FUN_004f10f0();
    _atexit((_func_4879 *)&LAB_00bce260);
  }
                    /* WARNING: Could not recover jumptable at 0x00494746. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(DAT_00fd94e0 + 4))();
  return;
}

