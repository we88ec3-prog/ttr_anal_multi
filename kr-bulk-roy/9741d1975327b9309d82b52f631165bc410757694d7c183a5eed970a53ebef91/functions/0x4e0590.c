
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e0590(void)

{
  undefined1 *puVar1;
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
  local_8 = 0xffffffff;
  if (DAT_00fc0fe4 != 0) {
    puVar1 = _DAT_00fc0fc8;
    if (DAT_00fc0fdc < 0x10) {
      puVar1 = &DAT_00fc0fc8;
    }
    FUN_006d9b30(&DAT_00fc0fc8,puVar1,1,DAT_00fc106c);
    DAT_00fc0fe4 = 0;
    FUN_00402a70(&DAT_00bf2375,0);
  }
  ExceptionList = local_10;
  return;
}

