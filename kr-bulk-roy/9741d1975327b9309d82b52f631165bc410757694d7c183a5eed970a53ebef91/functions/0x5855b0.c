
undefined * FUN_005855b0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090f9de;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe5b08 & 1) == 0) {
    DAT_00fe5b08 = DAT_00fe5b08 | 1;
    local_8 = 0;
    FUN_00584c40(&DAT_00fe5ae8);
    _atexit((_func_4879 *)&LAB_00bcf380);
  }
  ExceptionList = local_10;
  return &DAT_00fe5ae8;
}

