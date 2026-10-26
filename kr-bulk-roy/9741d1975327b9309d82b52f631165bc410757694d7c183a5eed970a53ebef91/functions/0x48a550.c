
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0048a550(void)

{
  if ((_DAT_00fd9408 & 1) == 0) {
    _DAT_00fd9408 = _DAT_00fd9408 | 1;
    DAT_00fd940c = 0;
    _DAT_00fd9410 = 0;
    DAT_00fd9414 = 0;
    _DAT_00fd9418 = 0;
  }
  return &DAT_00fd940c;
}

