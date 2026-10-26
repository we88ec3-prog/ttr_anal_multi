
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007911f0(void)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 4) != 2) {
    if (*(int *)(in_EAX + 4) == 4) {
      if (DAT_00fe3208 == (undefined *)0x0) {
        if ((_DAT_00fe353c & 1) == 0) {
          _DAT_00fe353c = _DAT_00fe353c | 1;
        }
        DAT_00fe3208 = &DAT_00fe3528;
      }
      FUN_007927f0();
      *(undefined1 *)(in_EAX + 0x14) = 1;
      return 1;
    }
    FUN_00791c90();
    FUN_00795030();
    *(undefined1 *)(in_EAX + 0x14) = 1;
  }
  return 1;
}

