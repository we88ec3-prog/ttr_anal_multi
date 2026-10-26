
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00791250(void)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 4) != 2) {
    if (*(int *)(in_EAX + 4) == 4) {
      if (DAT_00fe3210 == (undefined *)0x0) {
        if ((_DAT_00fe3538 & 1) == 0) {
          _DAT_00fe3538 = _DAT_00fe3538 | 1;
        }
        DAT_00fe3210 = &DAT_00fe3527;
      }
      FUN_00793440();
      *(undefined1 *)(in_EAX + 0x14) = 1;
      return 1;
    }
    FUN_00791cd0();
    FUN_00795d00();
    *(undefined1 *)(in_EAX + 0x14) = 1;
  }
  return 1;
}

