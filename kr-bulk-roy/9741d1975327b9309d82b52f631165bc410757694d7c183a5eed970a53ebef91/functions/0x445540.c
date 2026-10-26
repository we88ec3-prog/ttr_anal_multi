
void FUN_00445540(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00910d9b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00445ee0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_004ffa40(*DAT_00fb93f4,DAT_00fb93f4);
  FUN_0089120c(DAT_00fb93f4);
  if (DAT_00fb93e0 != 0) {
    FUN_0089120c(DAT_00fb93e0);
  }
  DAT_00fb93e0 = 0;
  DAT_00fb93e4 = 0;
  DAT_00fb93e8 = 0;
  if (DAT_00fb93d0 != 0) {
    FUN_0089120c(DAT_00fb93d0);
  }
  DAT_00fb93d0 = 0;
  DAT_00fb93d4 = 0;
  DAT_00fb93d8 = 0;
  ExceptionList = local_10;
  return;
}

