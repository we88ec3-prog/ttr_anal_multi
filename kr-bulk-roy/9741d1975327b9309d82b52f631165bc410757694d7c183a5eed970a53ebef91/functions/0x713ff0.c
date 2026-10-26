
undefined1 * FUN_00713ff0(void)

{
  if ((DAT_00fe364c & 1) == 0) {
    DAT_00fe364c = DAT_00fe364c | 1;
    DAT_00fe3648 = 0;
    _memset(&DAT_00fe3548,0,0x100);
  }
  return &DAT_00fe3548;
}

