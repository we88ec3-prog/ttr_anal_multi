
void FUN_004945f0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093880e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc7f1c & 1) == 0) {
    DAT_00fc7f1c = DAT_00fc7f1c | 1;
    local_8 = 0;
    FUN_0053c300(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bce1d0);
  }
  local_8 = 0xffffffff;
  (**(code **)(DAT_00fc7f20 + 4))(param_1,param_2,param_3);
  ExceptionList = local_10;
  return;
}

