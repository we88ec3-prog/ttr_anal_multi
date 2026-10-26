
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00832b60(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00909318;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00832d30(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (DAT_00fe3468 != 0) {
    FUN_0089120c(DAT_00fe3468);
  }
  DAT_00fe3468 = 0;
  _DAT_00fe346c = 0;
  _DAT_00fe3470 = 0;
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_0085e680(*DAT_00fe345c,DAT_00fe345c);
  FUN_0089120c(DAT_00fe345c);
  if (DAT_00fe3448 != 0) {
    FUN_0089120c(DAT_00fe3448);
  }
  DAT_00fe3448 = 0;
  _DAT_00fe344c = 0;
  _DAT_00fe3450 = 0;
  if (DAT_00fe3438 != 0) {
    FUN_0089120c(DAT_00fe3438);
  }
  DAT_00fe3438 = 0;
  DAT_00fe343c = 0;
  _DAT_00fe3440 = 0;
  ExceptionList = local_10;
  return;
}

