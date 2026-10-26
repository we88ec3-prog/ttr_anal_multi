
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007edac0(void)

{
  uint uVar1;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00909c03;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_0057ffd0(*DAT_00fe3330,DAT_00fe3330);
  FUN_0089120c(DAT_00fe3330,uVar1);
  if (DAT_00fe331c != 0) {
    FUN_007b2b80(local_1c);
    FUN_0089120c(DAT_00fe331c);
  }
  DAT_00fe331c = 0;
  DAT_00fe3320 = 0;
  _DAT_00fe3324 = 0;
  ExceptionList = local_10;
  return;
}

