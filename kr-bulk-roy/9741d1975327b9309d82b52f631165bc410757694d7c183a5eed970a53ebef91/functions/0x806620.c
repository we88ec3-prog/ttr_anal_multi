
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00806620(void)

{
  if ((_DAT_00fe33b4 & 1) == 0) {
    _DAT_00fe33b4 = _DAT_00fe33b4 | 1;
    DAT_00fe33b8 = (HANDLE)0x0;
    _DAT_00fe33bc = 0;
    _DAT_00fe33c0 = 0;
    DAT_00fe33b8 = CreateIoCompletionPort((HANDLE)0xffffffff,(HANDLE)0x0,0,0);
    _atexit((_func_4879 *)&LAB_00bd0bb0);
  }
  return &DAT_00fe33b8;
}

