
void FUN_005d94d0(char param_1)

{
  int in_ECX;
  
  if (param_1 == '\0') {
    if (*(int *)(in_ECX + 0x2a0) == 0) {
      FUN_0067f1f0(0);
      FUN_0067f1f0(1);
      FUN_0067f1f0(2);
      return;
    }
    FUN_0067f1f0(*(int *)(in_ECX + 0x2a0));
  }
  return;
}

