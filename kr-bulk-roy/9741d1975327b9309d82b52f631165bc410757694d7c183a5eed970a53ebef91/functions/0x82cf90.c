
void FUN_0082cf90(int param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00909550;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_0082e210(param_1);
  if (*(int *)(param_1 + 0x20) != 0) {
    FUN_00891d3d(*(int *)(param_1 + 0x20),uVar1);
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_005540c0(**(undefined4 **)(param_1 + 0x28),*(undefined4 **)(param_1 + 0x28));
  FUN_0089120c(*(undefined4 *)(param_1 + 0x28));
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_0082f1c0(*(undefined4 *)(param_1 + 0x14));
    FUN_0089120c(*(undefined4 *)(param_1 + 0x10));
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  ExceptionList = local_10;
  return;
}

