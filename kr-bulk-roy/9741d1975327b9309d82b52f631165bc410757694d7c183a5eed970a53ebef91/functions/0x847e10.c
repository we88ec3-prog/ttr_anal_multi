
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00847e10(void)

{
  if (DAT_00fe3508 == (undefined *)0x0) {
    if ((_DAT_00fe34ec & 1) == 0) {
      _DAT_00fe34ec = _DAT_00fe34ec | 1;
      FUN_00869c00();
    }
    DAT_00fe3508 = &DAT_00fe34f0;
  }
  return;
}

