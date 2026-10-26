
undefined * FUN_00489e00(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00910afe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fd93f4 & 1) == 0) {
    DAT_00fd93f4 = DAT_00fd93f4 | 1;
    local_8 = 0;
    FUN_00828c00();
    _atexit(FUN_00bcde40);
  }
  ExceptionList = local_10;
  return &DAT_00fd93f8;
}

