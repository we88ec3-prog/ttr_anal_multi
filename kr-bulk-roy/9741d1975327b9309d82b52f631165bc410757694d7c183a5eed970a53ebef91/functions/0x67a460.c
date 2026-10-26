
undefined * FUN_0067a460(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00926aae;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe3008 & 1) == 0) {
    DAT_00fe3008 = DAT_00fe3008 | 1;
    local_8 = 0;
    FUN_00513fa0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcff80);
  }
  ExceptionList = local_10;
  return &DAT_00fe3010;
}

