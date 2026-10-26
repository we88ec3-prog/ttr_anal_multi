
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006eb9f0(void)

{
  if (DAT_00fe36b0 != (void *)0x0) {
    _free(DAT_00fe36b0);
    DAT_00fe36b0 = (void *)0x0;
  }
  _DAT_00fe36b4 = 0;
  _DAT_00fe36b8 = 0;
  return;
}

