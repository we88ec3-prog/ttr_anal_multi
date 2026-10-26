
undefined * FUN_00461dd0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00917a4e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc0d44 & 1) == 0) {
    DAT_00fc0d44 = DAT_00fc0d44 | 1;
    local_8 = 0;
    FUN_00462200();
    _atexit(FUN_00bcd800);
  }
  ExceptionList = local_10;
  return &DAT_00fc0d48;
}

