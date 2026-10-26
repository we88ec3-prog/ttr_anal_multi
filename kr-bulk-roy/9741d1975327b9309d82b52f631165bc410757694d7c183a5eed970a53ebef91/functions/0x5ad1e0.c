
void FUN_005ad1e0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009161fe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 0;
    FUN_0074d990(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  local_8 = 0xffffffff;
  FUN_00753520();
  if (((uint)(*(int **)(param_1 + 0x23c))[10] >> 8 & 1) != 0) {
    (**(code **)(**(int **)(param_1 + 0x23c) + 0xd4))();
  }
  ExceptionList = local_10;
  return;
}

