
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046e490(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090b765;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (DAT_00fc0d84 != 0) {
    FUN_0046f650();
    FUN_0089120c(DAT_00fc0d84);
  }
  DAT_00fc0d84 = 0;
  DAT_00fc0d88 = 0;
  _DAT_00fc0d8c = 0;
  local_8 = 0;
  FUN_0046ec30(*DAT_00fc0d78,DAT_00fc0d78);
  FUN_0089120c(DAT_00fc0d78,uVar1);
  ExceptionList = local_10;
  return;
}

