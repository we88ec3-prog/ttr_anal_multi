
void FUN_0073d0e0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090f105;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00891d3d(*(undefined4 *)(param_1 + 0x44),DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_005540c0(**(undefined4 **)(param_1 + 0x30),*(undefined4 **)(param_1 + 0x30));
  FUN_0089120c(*(undefined4 *)(param_1 + 0x30));
  local_8 = 0xffffffff;
  FUN_0073e1c0(param_1 + 4);
  ExceptionList = local_10;
  return;
}

