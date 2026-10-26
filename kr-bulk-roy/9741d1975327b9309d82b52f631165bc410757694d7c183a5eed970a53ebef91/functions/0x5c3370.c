
void FUN_005c3370(int param_1)

{
  FUN_0059bd80(param_1);
  if (*(int *)(param_1 + 0x10) == 0xf43da) {
    FUN_005c3610();
  }
  else if (*(int *)(param_1 + 0x10) == 0xf43fd) {
    FUN_006c0170(param_1);
    return;
  }
  return;
}

