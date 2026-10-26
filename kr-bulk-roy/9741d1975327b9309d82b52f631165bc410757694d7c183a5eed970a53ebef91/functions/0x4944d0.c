
void FUN_004944d0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0094103e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc1cbc & 1) == 0) {
    DAT_00fc1cbc = DAT_00fc1cbc | 1;
    local_8 = 0;
    FUN_004fdac0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bce150);
  }
  local_8 = 0xffffffff;
  (**(code **)(DAT_00fc1cc0 + 4))(param_1,param_2,param_3);
  ExceptionList = local_10;
  return;
}

