
void FUN_0059ce30(int param_1)

{
  int in_ECX;
  
  if (param_1 == 0) {
    FUN_005fd250();
  }
  *(int *)(*(int *)(in_ECX + 0x168) + 0x128) = param_1;
  *(undefined1 *)(*(int *)(in_ECX + 0x168) + 0x124) = 0;
  (**(code **)(**(int **)(in_ECX + 0x168) + 0xd4))();
  return;
}

