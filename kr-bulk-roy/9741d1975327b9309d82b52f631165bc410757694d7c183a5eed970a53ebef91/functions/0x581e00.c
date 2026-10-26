
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00581e00(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090fdbb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (DAT_00fc1b94 != 0) {
    FUN_0055f320(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    DAT_00fc1b94 = 0;
  }
  FUN_007b6d70();
  FUN_0089120c(DAT_00fc1bdc);
  DAT_00fc1bdc = 0;
  FUN_00513450();
  if (0xf < DAT_00fc1bac) {
    FUN_0089120c(DAT_00fc1b98);
  }
  DAT_00fc1bac = 0xf;
  _DAT_00fc1ba8 = 0;
  DAT_00fc1b98 = DAT_00fc1b98 & 0xffffff00;
  ExceptionList = local_10;
  return;
}

