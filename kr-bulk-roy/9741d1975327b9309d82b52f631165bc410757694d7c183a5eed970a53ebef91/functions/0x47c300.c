
undefined1 * FUN_0047c300(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091786e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc0fc0 & 1) == 0) {
    DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
    local_8 = 0;
    FUN_006d8e50(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcdbb0);
  }
  ExceptionList = local_10;
  return &DAT_00fc0fc8;
}

