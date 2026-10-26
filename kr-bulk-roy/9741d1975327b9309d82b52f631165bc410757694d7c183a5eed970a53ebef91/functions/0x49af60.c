
void FUN_0049af60(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00910ad1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc1200 & 1) == 0) {
    DAT_00fc1200 = DAT_00fc1200 | 1;
    local_8 = 0;
    FUN_00805460(&DAT_00fc1208);
    _atexit((_func_4879 *)&LAB_00bce670);
  }
  DAT_00fba858 = &DAT_00fc1208;
  local_8 = 1;
  FUN_00805460(&DAT_00fc1208);
  _atexit((_func_4879 *)&LAB_0049af50);
  DAT_00fba85c = 0;
  ExceptionList = local_10;
  return;
}

