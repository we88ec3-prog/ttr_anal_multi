
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00589f60(int param_1)

{
  undefined4 in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091db62;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc30);
  }
  local_8 = 0xffffffff;
  FUN_005c6db0(&DAT_00f94398,in_ECX);
  if ((DAT_00fe2898 & 1) == 0) {
    DAT_00fe2898 = DAT_00fe2898 | 1;
    local_8 = 1;
    FUN_00773dd0();
    _atexit((_func_4879 *)&LAB_00bcf3e0);
    local_8 = 0xffffffff;
  }
  FUN_00774720(in_ECX);
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 2;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  FUN_0074e4d0(&DAT_00f94810,in_ECX);
  FUN_005cb040();
  (**(code **)(**(int **)(param_1 + 0x30) + 0x14))();
  if ((DAT_00fe2898 & 1) == 0) {
    DAT_00fe2898 = DAT_00fe2898 | 1;
    local_8 = 3;
    FUN_00773dd0();
    _atexit((_func_4879 *)&LAB_00bcf3e0);
    local_8 = 0xffffffff;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 4;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  _DAT_00f95cbc = FUN_007742f0("UIDefaultShader");
  if ((DAT_00fe2898 & 1) == 0) {
    DAT_00fe2898 = DAT_00fe2898 | 1;
    local_8 = 5;
    FUN_00773dd0();
    _atexit((_func_4879 *)&LAB_00bcf3e0);
    local_8 = 0xffffffff;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 6;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  _DAT_00f95cc0 = FUN_007742f0("UIGrayShader");
  ExceptionList = local_10;
  return;
}

