
void FUN_005447f0(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0xf0) == 0) {
    *(undefined4 *)(param_1 + 0xf0) = param_2;
    return;
  }
  if (*(int *)(*(int *)(param_1 + 0xf0) + 0x24) != 0) {
    FUN_007be5f0();
  }
  if (*(int *)(param_1 + 0xf0) != 0) {
    FUN_004c7db0();
    *(undefined4 *)(param_1 + 0xf0) = 0;
    *(undefined4 *)(param_1 + 0xf0) = param_2;
    return;
  }
  *(undefined4 *)(param_1 + 0xf0) = param_2;
  return;
}

