
void FUN_005ac5c0(int param_1)

{
  code *pcVar1;
  int in_ECX;
  
  FUN_0059b8c0(param_1);
  if (*(int *)(param_1 + 0x10) == 0xf4351) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x220) + 0xd4);
    (*(int **)(in_ECX + 0x220))[0x30] = 0;
    (*pcVar1)();
  }
  return;
}

