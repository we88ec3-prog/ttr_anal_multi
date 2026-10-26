
undefined * FUN_00798d70(void)

{
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090a35e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe321c & 1) == 0) {
    DAT_00fe321c = DAT_00fe321c | 1;
    local_8 = 0;
    FUN_007d0fb0(&local_11);
    _atexit((_func_4879 *)&LAB_00bd09c0);
  }
  ExceptionList = local_10;
  return &DAT_00fe3220;
}

