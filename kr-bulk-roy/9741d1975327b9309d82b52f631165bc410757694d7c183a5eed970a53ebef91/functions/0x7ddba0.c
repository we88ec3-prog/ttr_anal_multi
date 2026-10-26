
void FUN_007ddba0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090c3da;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_007ddc50(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_0057ffd0(*DAT_00fe32f0,DAT_00fe32f0);
  FUN_0089120c(DAT_00fe32f0);
  local_8 = 3;
  FUN_0057ffd0(*DAT_00fe32e0,DAT_00fe32e0);
  FUN_0089120c(DAT_00fe32e0);
  ExceptionList = local_10;
  return;
}

