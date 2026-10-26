
void FUN_00802220(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    *(undefined4 *)(in_ECX + 0x90) = 0x3f800000;
    *(undefined4 *)(in_ECX + 0xec) = param_1;
    return;
  }
  *(undefined4 *)(in_ECX + 0x90) = param_1;
  return;
}

