
void FUN_007d8890(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00905516;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_007d8920(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (0xf < *(uint *)(param_1 + 0x90)) {
    FUN_0089120c(*(undefined4 *)(param_1 + 0x7c));
  }
  *(undefined4 *)(param_1 + 0x90) = 0xf;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined1 *)(param_1 + 0x7c) = 0;
  if (*(int *)(param_1 + 0x5c) != 0) {
    FUN_0089120c(*(int *)(param_1 + 0x5c));
  }
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  ExceptionList = local_10;
  return;
}

