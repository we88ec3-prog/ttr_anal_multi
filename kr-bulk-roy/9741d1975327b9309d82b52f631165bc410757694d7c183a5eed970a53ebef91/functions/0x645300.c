
void FUN_00645300(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093324e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb11e0 & 1) == 0) {
    DAT_00fb11e0 = DAT_00fb11e0 | 1;
    local_8 = 0;
    FUN_004d4d10();
    _atexit((_func_4879 *)&LAB_00bccef0);
  }
  local_8 = 0xffffffff;
  FUN_004026e0(&DAT_00fb12d8,0,0xffffffff);
  FUN_006473e0();
  ExceptionList = local_10;
  return;
}

