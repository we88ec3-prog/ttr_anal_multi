
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040cff0(void)

{
  uint uVar1;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090b933;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_005540c0(*DAT_00fab11c,DAT_00fab11c);
  FUN_0089120c(DAT_00fab11c,uVar1);
  if (DAT_00fab108 != 0) {
    FUN_0049ad50(local_1c);
    FUN_0089120c(DAT_00fab108);
  }
  DAT_00fab108 = 0;
  DAT_00fab10c = 0;
  _DAT_00fab110 = 0;
  ExceptionList = local_10;
  return;
}

