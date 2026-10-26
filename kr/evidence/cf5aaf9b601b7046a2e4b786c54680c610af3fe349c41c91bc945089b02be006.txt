
void FUN_00494440(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00947dfe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_8 = 0;
    FUN_004ffe60(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccf00);
  }
  local_8 = 0xffffffff;
  (**(code **)(DAT_00fab2a0 + 4))(param_1,param_2,param_3);
  ExceptionList = local_10;
  return;
}

