
void FUN_007f7190(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091c4ce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe1770 & 1) == 0) {
    DAT_00fe1770 = DAT_00fe1770 | 1;
    local_8 = 0;
    FUN_007b7da0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce790);
  }
  local_8 = 0xffffffff;
  FUN_007b8090();
  ExceptionList = local_10;
  return;
}

