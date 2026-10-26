
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00820400(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090e942;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if (DAT_00fb7c04 != 0) {
    FUN_0089120c(DAT_00fb7c04,uVar1);
  }
  DAT_00fb7c04 = 0;
  _DAT_00fb7c08 = 0;
  _DAT_00fb7c0c = 0;
  if (DAT_00fb7bf0 != 0) {
    FUN_0089120c(DAT_00fb7bf0,uVar1);
  }
  DAT_00fb7bf0 = 0;
  DAT_00fb7bf4 = 0;
  _DAT_00fb7bf8 = 0;
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_00821100(*DAT_00fb7be4,DAT_00fb7be4);
  FUN_0089120c(DAT_00fb7be4,uVar1);
  local_8 = 2;
  FUN_00821060(*DAT_00fb7bd4,DAT_00fb7bd4);
  FUN_0089120c(DAT_00fb7bd4);
  ExceptionList = local_10;
  return;
}

