
void FUN_006d5eb0(int param_1)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x78) = param_1;
  if (param_1 < 0x80) {
    *(undefined4 *)(in_ECX + 0x78) = 0x100;
  }
  if (0x400 < *(int *)(in_ECX + 0x78)) {
    *(undefined4 *)(in_ECX + 0x78) = 0x400;
  }
  return;
}

