
void FUN_0044ae90(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090b7df;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_0044bab0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_005540c0(*DAT_00fb93a8,DAT_00fb93a8);
  FUN_0089120c(DAT_00fb93a8);
  local_8 = 3;
  FUN_0044b720(*DAT_00fb9398,DAT_00fb9398);
  FUN_0089120c(DAT_00fb9398);
  ExceptionList = local_10;
  return;
}

