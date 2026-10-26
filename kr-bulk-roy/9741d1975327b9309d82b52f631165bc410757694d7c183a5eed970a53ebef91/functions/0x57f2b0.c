
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0057f2b0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009210c6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_0089120c(DAT_00fc1c48,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_0089120c(DAT_00fc1c44);
  FUN_0089120c(DAT_00fc1c40);
  FUN_0089120c(DAT_00fc1c3c);
  FUN_00580090(&DAT_00fc1c2c);
  if (DAT_00fc1c50 != 0) {
    FUN_005800f0(DAT_00fc1c54,&DAT_00fc1bf8);
    FUN_0089120c(DAT_00fc1c50);
  }
  DAT_00fc1c50 = 0;
  DAT_00fc1c54 = 0;
  _DAT_00fc1c58 = 0;
  if (DAT_00fc1c2c != 0) {
    FUN_0089120c(DAT_00fc1c2c);
  }
  DAT_00fc1c2c = 0;
  _DAT_00fc1c30 = 0;
  _DAT_00fc1c34 = 0;
  ExceptionList = local_10;
  return;
}

