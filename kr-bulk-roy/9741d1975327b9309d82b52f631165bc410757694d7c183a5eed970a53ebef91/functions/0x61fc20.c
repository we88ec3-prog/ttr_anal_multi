
void FUN_0061fc20(byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090ab2e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 0;
    FUN_0054f850(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  if (DAT_00fb90fb < param_1) {
    param_1 = DAT_00fb90fb;
  }
  DAT_00fb90f9 = DAT_00fb90fa;
  if (DAT_00fb90fa <= param_1) {
    DAT_00fb90f9 = param_1;
  }
  ExceptionList = local_10;
  return;
}

