
void FUN_0058a150(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091dada;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 0;
    FUN_0074d990(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  local_8 = 0xffffffff;
  FUN_0074e8a0();
  if ((DAT_00fe2898 & 1) == 0) {
    DAT_00fe2898 = DAT_00fe2898 | 1;
    local_8 = 1;
    FUN_00773dd0();
    _atexit((_func_4879 *)&LAB_00bcf3e0);
    local_8 = 0xffffffff;
  }
  FUN_007747b0();
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 2;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  FUN_005c6e60();
  FUN_005cb0a0();
  (**(code **)(**(int **)(param_1 + 0x30) + 0x18))();
  ExceptionList = local_10;
  return;
}

