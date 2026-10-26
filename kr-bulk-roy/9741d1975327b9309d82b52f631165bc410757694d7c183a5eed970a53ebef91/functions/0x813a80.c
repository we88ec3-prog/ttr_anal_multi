
void FUN_00813a80(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090c214;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
  FUN_00817be0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_00817cd0(&DAT_00fb11bc);
  local_8._0_1_ = 3;
  FUN_005540c0(*DAT_00fb11d0,DAT_00fb11d0);
  FUN_0089120c(DAT_00fb11d0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_005540c0(*DAT_00fb11c0,DAT_00fb11c0);
  FUN_0089120c(DAT_00fb11c0);
  local_8 = 5;
  FUN_00817860(*DAT_00fb11b0,DAT_00fb11b0);
  FUN_0089120c(DAT_00fb11b0);
  ExceptionList = local_10;
  return;
}

