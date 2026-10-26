
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004adcd0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090b57e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe18a0 & 1) == 0) {
    DAT_00fe18a0 = DAT_00fe18a0 | 1;
    local_8 = 0;
    FUN_004f0ae0();
    _DAT_00fe18bc = 1;
    DAT_00fe18be = 0;
    _DAT_00fe18c0 = 0;
    _atexit((_func_4879 *)&LAB_00bce8c0);
  }
  ExceptionList = local_10;
  return &DAT_00fe18a4;
}

