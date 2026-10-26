
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005408b0(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090af4b;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 2;
  FUN_004ca160(*DAT_00fc0e80,DAT_00fc0e80);
  FUN_0089120c(DAT_00fc0e80,uVar1);
  FUN_007b6d70();
  FUN_007b6d70();
  FUN_0089120c(DAT_00fc0e64);
  DAT_00fc0e64 = 0;
  if (0xf < DAT_00fc0e5c) {
    FUN_0089120c(DAT_00fc0e48);
  }
  DAT_00fc0e5c = 0xf;
  _DAT_00fc0e58 = 0;
  DAT_00fc0e48 = DAT_00fc0e48 & 0xffffff00;
  ExceptionList = local_10;
  return;
}

