
void FUN_00407330(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009169be;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 0;
    FUN_0074d990(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  local_8 = 0xffffffff;
  FUN_007531a0(&DAT_00f94810,param_2,param_3,param_4,param_5);
  ExceptionList = local_10;
  return;
}

