
void FUN_008c5c50(int param_1)

{
  *(undefined4 *)(param_1 + 0x1c) = 0;
  if ((*(int *)(param_1 + 0x24) != 0) && (*(int *)(param_1 + 0x20) != 0)) {
    FUN_008b9f80(*(int *)(param_1 + 0x24),*(int *)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return;
}

