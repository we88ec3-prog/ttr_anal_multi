
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0055c720(void)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00938680;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_0055e2e0(&DAT_00fe1ef4,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  iVar1 = DAT_00fe1ef0;
  if (DAT_00fe1ef0 != 0) {
    if (*(int *)(DAT_00fe1ef0 + 8) != 0) {
      FUN_006f75f0();
    }
    FUN_0089120c(iVar1);
    DAT_00fe1ef0 = 0;
  }
  FUN_006f75f0();
  if (0xf < DAT_00fe1f18) {
    FUN_0089120c(DAT_00fe1f04);
  }
  DAT_00fe1f18 = 0xf;
  _DAT_00fe1f14 = 0;
  DAT_00fe1f04 = DAT_00fe1f04 & 0xffffff00;
  local_8 = 2;
  FUN_005540c0(*DAT_00fe1ef8,DAT_00fe1ef8);
  FUN_0089120c(DAT_00fe1ef8);
  ExceptionList = local_10;
  return;
}

