
void FUN_004e3b30(undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093031e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe1bd8 & 1) == 0) {
    DAT_00fe1bd8 = DAT_00fe1bd8 | 1;
    local_8 = 0;
    FUN_00533f80(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bced30);
  }
  local_8 = 0xffffffff;
  FUN_00535680(param_1);
  ExceptionList = local_10;
  return;
}

