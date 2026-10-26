
void FUN_008bab90(int param_1,undefined4 *param_2)

{
  if (param_1 == 0) {
    *param_2 = 0;
    return;
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    FUN_008b9f80(*(undefined4 *)(param_1 + 0x1c),*param_2);
    *param_2 = 0;
    *param_2 = 0;
    return;
  }
  *param_2 = 0;
  return;
}

