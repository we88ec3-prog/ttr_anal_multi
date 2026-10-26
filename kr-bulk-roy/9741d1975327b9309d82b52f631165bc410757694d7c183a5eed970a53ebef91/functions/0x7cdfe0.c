
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007cdfe0(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090c4b2;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if (DAT_00fe3270 != 0) {
    FUN_0089120c(DAT_00fe3270,uVar1);
  }
  DAT_00fe3270 = 0;
  _DAT_00fe3274 = 0;
  _DAT_00fe3278 = 0;
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_0057ffd0(*DAT_00fe3264,DAT_00fe3264);
  FUN_0089120c(DAT_00fe3264,uVar1);
  local_8 = 2;
  FUN_007d0070(*DAT_00fe3254,DAT_00fe3254);
  FUN_0089120c(DAT_00fe3254);
  ExceptionList = local_10;
  return;
}

