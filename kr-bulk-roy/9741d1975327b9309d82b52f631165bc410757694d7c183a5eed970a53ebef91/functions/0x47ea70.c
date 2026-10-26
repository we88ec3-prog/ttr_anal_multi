
void FUN_0047ea70(int param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090dd0e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 2;
  FUN_00825810(**(undefined4 **)(param_1 + 0x38),*(undefined4 **)(param_1 + 0x38));
  FUN_0089120c(*(undefined4 *)(param_1 + 0x38),uVar1);
  if (*(int *)(param_1 + 0x24) != 0) {
    FUN_0089120c(*(int *)(param_1 + 0x24),uVar1);
  }
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  if (7 < *(uint *)(param_1 + 0x1c)) {
    FUN_0089120c(*(undefined4 *)(param_1 + 8),uVar1);
  }
  *(undefined4 *)(param_1 + 0x1c) = 7;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  ExceptionList = local_10;
  return;
}

