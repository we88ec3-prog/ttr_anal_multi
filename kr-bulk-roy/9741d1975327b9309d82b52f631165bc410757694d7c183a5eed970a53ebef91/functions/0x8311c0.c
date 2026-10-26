
void FUN_008311c0(void)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar1 = DAT_00fe30c8;
  puStack_c = &LAB_0090bf3f;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (DAT_00fe30c8 != 0) {
    local_8 = 3;
    FUN_00833b70(**(undefined4 **)(DAT_00fe30c8 + 4),*(undefined4 **)(DAT_00fe30c8 + 4));
    FUN_0089120c(*(undefined4 *)(iVar1 + 4));
    FUN_0089120c(iVar1);
    DAT_00fe30c8 = 0;
  }
  iVar1 = DAT_00fe30cc;
  if (DAT_00fe30cc != 0) {
    local_8 = CONCAT31(local_8._1_3_,4);
    FUN_00834f90(**(undefined4 **)(DAT_00fe30cc + 4),*(undefined4 **)(DAT_00fe30cc + 4));
    FUN_0089120c(*(undefined4 *)(iVar1 + 4));
    FUN_0089120c(iVar1);
    DAT_00fe30cc = 0;
  }
  iVar1 = DAT_00fe30d0;
  if (DAT_00fe30d0 != 0) {
    local_8 = CONCAT31(local_8._1_3_,5);
    FUN_00831fd0(**(undefined4 **)(DAT_00fe30d0 + 4),*(undefined4 **)(DAT_00fe30d0 + 4));
    FUN_0089120c(*(undefined4 *)(iVar1 + 4));
    FUN_0089120c(iVar1);
    DAT_00fe30d0 = 0;
  }
  iVar1 = DAT_00fe30d4;
  if (DAT_00fe30d4 != 0) {
    local_8 = CONCAT31(local_8._1_3_,6);
    FUN_00835ce0(**(undefined4 **)(DAT_00fe30d4 + 4),*(undefined4 **)(DAT_00fe30d4 + 4));
    FUN_0089120c(*(undefined4 *)(iVar1 + 4));
    FUN_0089120c(iVar1);
    DAT_00fe30d4 = 0;
  }
  local_8._0_1_ = 7;
  FUN_005540c0(*DAT_00fe30fc,DAT_00fe30fc);
  FUN_0089120c(DAT_00fe30fc);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_005540c0(*DAT_00fe30ec,DAT_00fe30ec);
  FUN_0089120c(DAT_00fe30ec);
  local_8 = 9;
  FUN_005540c0(*DAT_00fe30dc,DAT_00fe30dc);
  FUN_0089120c(DAT_00fe30dc);
  ExceptionList = local_10;
  return;
}

