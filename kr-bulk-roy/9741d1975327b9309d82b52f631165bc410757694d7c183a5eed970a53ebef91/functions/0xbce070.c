
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00bce070(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00a07fc7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  _DAT_00fe48e0 = Package::CPackageMgr::vftable;
  local_8 = 0;
  if (DAT_00fe49e4 != (undefined4 *)0x0) {
    (**(code **)*DAT_00fe49e4)(1,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    DAT_00fe49e4 = (undefined4 *)0x0;
  }
  local_8 = 1;
  FUN_00714eb0();
  FUN_0089120c(DAT_00fe49e8);
  ExceptionList = local_10;
  return;
}

