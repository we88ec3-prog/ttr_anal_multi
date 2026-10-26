
void FUN_006042b0(void)

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
  FUN_004ff140();
  FUN_00605410();
  ExceptionList = local_10;
  return;
}

