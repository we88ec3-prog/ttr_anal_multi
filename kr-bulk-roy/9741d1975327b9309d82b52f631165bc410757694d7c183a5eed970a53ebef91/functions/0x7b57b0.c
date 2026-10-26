
void FUN_007b57b0(void)

{
  char cVar1;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00914f27;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 6;
  FUN_007b7020(local_14);
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  local_8 = CONCAT31(local_8._1_3_,7);
  cVar1 = FUN_007b6af0(local_30);
  while (cVar1 != '\0') {
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_00fba6d0);
    cVar1 = FUN_007b6af0(local_30);
  }
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  FUN_00552640(&DAT_00fd94cc);
  FUN_0089120c(DAT_00fd94cc);
  local_8._0_1_ = 8;
  FUN_0057ffd0(*DAT_00fd94c0,DAT_00fd94c0);
  FUN_0089120c(DAT_00fd94c0);
  FUN_007b6d70();
  FUN_0089120c(DAT_00fd9498);
  DAT_00fd9498 = 0;
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_00fd9480);
  FUN_006df330();
  FUN_0089120c(DAT_00fd9468);
  DAT_00fd9468 = 0;
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_00fd9450);
  local_8._0_1_ = 9;
  FUN_005540c0(*DAT_00fd9444,DAT_00fd9444);
  FUN_0089120c(DAT_00fd9444);
  local_8 = CONCAT31(local_8._1_3_,10);
  FUN_005540c0(*DAT_00fd9434,DAT_00fd9434);
  FUN_0089120c(DAT_00fd9434);
  local_8 = 0xb;
  FUN_007b6de0(*DAT_00fd9424,DAT_00fd9424);
  FUN_0089120c(DAT_00fd9424);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

