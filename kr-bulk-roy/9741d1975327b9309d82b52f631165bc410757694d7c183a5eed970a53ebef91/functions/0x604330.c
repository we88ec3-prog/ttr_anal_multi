
void FUN_00604330(void)

{
  uint uVar1;
  int *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0094348c;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fc1cbc & 1) == 0) {
    DAT_00fc1cbc = DAT_00fc1cbc | 1;
    local_8 = 0;
    FUN_004fdac0(uVar1);
    _atexit(FUN_00bce150);
  }
  local_8 = 0xffffffff;
  if (DAT_00fc7efc != 0) {
    if ((DAT_00fc1cbc & 1) == 0) {
      DAT_00fc1cbc = DAT_00fc1cbc | 1;
      local_8 = 1;
      FUN_004fdac0(uVar1);
      _atexit(FUN_00bce150);
    }
    local_8 = 0xffffffff;
    FUN_004ff1a0(1);
    FUN_00605410();
    ExceptionList = local_10;
    return;
  }
  (**(code **)(*unaff_EDI + 0xd4))();
  ExceptionList = local_10;
  return;
}

