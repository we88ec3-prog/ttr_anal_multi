
void FUN_00564580(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091b21e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc0fc0 & 1) == 0) {
    DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
    local_8 = 0;
    FUN_006d8e50(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcdbb0);
  }
  local_8 = 0xffffffff;
  FUN_006d9da0((float)param_1 / 1000.0);
  ExceptionList = local_10;
  return;
}

