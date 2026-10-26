
void FUN_006a7840(int param_1)

{
  if (*(int *)(param_1 + 0x10) == 0x578) {
    FUN_006a7870();
  }
  else if (*(int *)(param_1 + 0x10) == 0xf4407) {
    FUN_006a7970();
    return;
  }
  return;
}

