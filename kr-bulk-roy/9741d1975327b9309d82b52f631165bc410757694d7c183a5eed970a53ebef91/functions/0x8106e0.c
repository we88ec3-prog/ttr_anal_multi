
void FUN_008106e0(int param_1)

{
  int in_ECX;
  
  if (0x20000 < param_1) {
    *(undefined4 *)(in_ECX + 0x20018) = 0x20000;
    return;
  }
  *(int *)(in_ECX + 0x20018) = param_1;
  return;
}

