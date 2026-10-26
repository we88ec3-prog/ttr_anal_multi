
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0051c220(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090d2e2;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
  FUN_0051dd40(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_0051be70(&DAT_00f8d938);
  if (DAT_00f8d928 != 0) {
    FUN_0089120c(DAT_00f8d928);
  }
  DAT_00f8d928 = 0;
  DAT_00f8d92c = 0;
  _DAT_00f8d930 = 0;
  local_8 = 3;
  FUN_0051d8f0(*DAT_00f8d91c,DAT_00f8d91c);
  FUN_0089120c(DAT_00f8d91c);
  ExceptionList = local_10;
  return;
}

