
undefined * FUN_005854b0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090fa0e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_8 = 0;
    FUN_00584c40(&DAT_00fe5b0c);
    _atexit(FUN_00bcf370);
  }
  ExceptionList = local_10;
  return &DAT_00fe5b0c;
}

