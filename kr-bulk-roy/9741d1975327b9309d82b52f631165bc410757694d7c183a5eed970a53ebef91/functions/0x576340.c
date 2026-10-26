
void FUN_00576340(int param_1)

{
  FUN_007b6d70();
  FUN_0089120c(*(undefined4 *)(param_1 + 0x2c));
  *(undefined4 *)(param_1 + 0x2c) = 0;
  FUN_006df330();
  FUN_0089120c(*(undefined4 *)(param_1 + 0x14));
  *(undefined4 *)(param_1 + 0x14) = 0;
  if (*(int *)(param_1 + 4) != 0) {
    FUN_00440a80();
    FUN_0089120c(*(undefined4 *)(param_1 + 4));
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}

