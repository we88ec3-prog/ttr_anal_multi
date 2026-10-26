
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004dc660(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090b4f5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_004dd630(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (DAT_00fab0ec != 0) {
    FUN_0089120c(DAT_00fab0ec);
  }
  DAT_00fab0ec = 0;
  _DAT_00fab0f0 = 0;
  _DAT_00fab0f4 = 0;
  local_8 = 2;
  FUN_004dd530(*DAT_00fab0e0,DAT_00fab0e0);
  FUN_0089120c(DAT_00fab0e0);
  ExceptionList = local_10;
  return;
}

