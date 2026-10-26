
void FUN_0049b000(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090dbfe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc1200 & 1) == 0) {
    DAT_00fc1200 = DAT_00fc1200 | 1;
    local_8 = 0;
    FUN_00805460(&DAT_00fc1208);
    _atexit((_func_4879 *)&LAB_00bce670);
  }
  DAT_00fba858 = &DAT_00fc1208;
  ExceptionList = local_10;
  return;
}

