
void FUN_006256f0(byte param_1)

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
  if (DAT_00fb92ff < param_1) {
    param_1 = DAT_00fb92ff;
  }
  DAT_00fb92fd = DAT_00fb92fe;
  if (DAT_00fb92fe <= param_1) {
    DAT_00fb92fd = param_1;
  }
  ExceptionList = local_10;
  return;
}

