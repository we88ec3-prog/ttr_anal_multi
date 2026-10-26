
undefined4 * FUN_00611aa0(undefined4 param_1)

{
  int in_ECX;
  undefined4 *unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091a79e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc0dc4 & 1) == 0) {
    DAT_00fc0dc4 = DAT_00fc0dc4 | 1;
    local_8 = 0;
    FUN_0052a3b0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bcd980);
  }
  local_8 = 0xffffffff;
  FUN_0052a340(&param_1);
  if ((in_ECX != DAT_00fc0dcc) && (in_ECX != -0x10)) {
    FUN_004026e0(in_ECX + 0x14,0,0xffffffff);
  }
  if (7 < (uint)unaff_ESI[5]) {
    ExceptionList = local_10;
    return (undefined4 *)*unaff_ESI;
  }
  ExceptionList = local_10;
  return unaff_ESI;
}

