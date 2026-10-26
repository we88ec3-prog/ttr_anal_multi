
void FUN_005afe70(int param_1)

{
  int in_ECX;
  
  FUN_0059bd80(param_1);
  if (*(int *)(param_1 + 0x10) == 0xf4406) {
    FUN_005ac6e0(in_ECX);
  }
  if (*(int *)(param_1 + 0x10) == 0xf4401) {
    FUN_006ba890(*(undefined4 *)(in_ECX + 0x22c),*(undefined4 *)(param_1 + 0x14));
  }
  return;
}

