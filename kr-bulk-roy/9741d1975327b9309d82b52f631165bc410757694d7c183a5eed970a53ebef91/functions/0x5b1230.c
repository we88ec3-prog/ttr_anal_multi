
void FUN_005b1230(int param_1)

{
  int in_ECX;
  
  FUN_005b7f80(param_1);
  if (*(int *)(param_1 + 0x10) == 0xf439e) {
    FUN_005b1380(in_ECX);
  }
  else if (*(int *)(param_1 + 0x10) == 0xf4404) {
    FUN_006b2f40(*(undefined4 *)(in_ECX + 0x2fc));
    return;
  }
  return;
}

