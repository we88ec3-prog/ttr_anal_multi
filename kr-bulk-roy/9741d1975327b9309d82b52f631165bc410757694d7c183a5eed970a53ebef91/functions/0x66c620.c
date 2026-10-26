
void FUN_0066c620(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0x709) {
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xf0) + 0x20)) {
      FUN_0066bbd0(in_ECX);
      return;
    }
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xf4) + 0x20)) {
      FUN_0066c510(in_ECX);
      return;
    }
  }
  else if (iVar1 == 0x70a) {
    if (*(int *)(param_1 + 8) == (*(int **)(in_ECX + 0xf4))[8]) {
      (**(code **)(**(int **)(in_ECX + 0xf4) + 0x90))(0);
      (**(code **)(**(int **)(in_ECX + 0xf0) + 0x90))(0);
      (**(code **)(**(int **)(in_ECX + 0xf8) + 0x90))(0);
      FUN_0066c090(in_ECX);
      return;
    }
  }
  else if ((iVar1 == 0x578) && (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xf8) + 0x20)))
  {
    (**(code **)(**(int **)(in_ECX + 0xf4) + 0x90))(0);
    (**(code **)(**(int **)(in_ECX + 0xf0) + 0x90))(0);
    (**(code **)(**(int **)(in_ECX + 0xf8) + 0x90))(0);
    FUN_0066c090(in_ECX);
  }
  return;
}

