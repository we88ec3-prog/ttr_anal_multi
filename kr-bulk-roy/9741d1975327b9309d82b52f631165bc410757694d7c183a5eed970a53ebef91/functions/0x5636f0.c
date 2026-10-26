
void FUN_005636f0(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  FUN_0082ef00(&param_1);
  if ((in_ECX != *(int *)(in_ECX + 0x1c)) && (*(int *)(in_ECX + 0x10) != 0)) {
    *(undefined4 *)(*(int *)(in_ECX + 0x10) + 0x434) = param_2;
  }
  return;
}

