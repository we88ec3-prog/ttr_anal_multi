
void FUN_005045c0(int param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090d5be;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if (*(int *)(param_1 + 0x94) != 0) {
    FUN_00516210(*(undefined4 *)(param_1 + 0x98));
    FUN_0089120c(*(undefined4 *)(param_1 + 0x94));
  }
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_004ffa40(**(undefined4 **)(param_1 + 0x6c),*(undefined4 **)(param_1 + 0x6c));
  FUN_0089120c(*(undefined4 *)(param_1 + 0x6c),uVar1);
  if (7 < *(uint *)(param_1 + 0x60)) {
    FUN_0089120c(*(undefined4 *)(param_1 + 0x4c),uVar1);
  }
  *(undefined4 *)(param_1 + 0x60) = 7;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined2 *)(param_1 + 0x4c) = 0;
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_0089120c(*(int *)(param_1 + 0x10),uVar1);
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  ExceptionList = local_10;
  return;
}

