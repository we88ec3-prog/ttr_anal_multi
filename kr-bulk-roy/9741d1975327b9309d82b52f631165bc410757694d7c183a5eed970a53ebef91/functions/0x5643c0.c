
void FUN_005643c0(undefined4 param_1,undefined4 param_2)

{
  undefined2 uVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091b2a8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 0;
    FUN_0054f850(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 1;
    FUN_0054f850(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  if ((DAT_00fc0fc0 & 1) == 0) {
    DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
    local_8 = 2;
    FUN_006d8e50();
    _atexit((_func_4879 *)&LAB_00bcdbb0);
    if ((DAT_00fc0fc0 & 1) == 0) {
      DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
      local_8 = 3;
      FUN_006d8e50();
      _atexit((_func_4879 *)&LAB_00bcdbb0);
    }
  }
  local_8 = 0xffffffff;
  FUN_008fed10();
  FUN_006daa70();
  uVar1 = FUN_008fed10();
  FUN_006d9b30(&DAT_00fc0fc8,param_1,param_2,uVar1);
  ExceptionList = local_10;
  return;
}

