
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00825180(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090963d;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_00825810(*DAT_00fbad04,DAT_00fbad04);
  FUN_0089120c(DAT_00fbad04,uVar1);
  if (DAT_00fbacf0 != 0) {
    FUN_0089120c(DAT_00fbacf0,uVar1);
  }
  DAT_00fbacf0 = 0;
  DAT_00fbacf4 = 0;
  _DAT_00fbacf8 = 0;
  ExceptionList = local_10;
  return;
}

