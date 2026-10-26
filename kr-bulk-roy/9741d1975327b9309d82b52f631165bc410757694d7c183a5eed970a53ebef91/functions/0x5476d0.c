
void FUN_005476d0(undefined4 param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090aebe;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00545040(param_1);
  if ((DAT_00fb7a20 & 1) == 0) {
    DAT_00fb7a20 = DAT_00fb7a20 | 1;
    local_8 = 0;
    FUN_00548da0(uVar1);
    _atexit(FUN_00bcd370);
  }
  FUN_00549490(param_1);
  ExceptionList = local_10;
  return;
}

