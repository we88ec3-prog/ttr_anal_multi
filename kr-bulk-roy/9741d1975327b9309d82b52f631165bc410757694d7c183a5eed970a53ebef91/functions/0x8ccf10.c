
void FUN_008ccf10(void)

{
  int in_ECX;
  undefined4 in_EDX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    *(undefined4 *)(*(int *)(in_ECX + 0x14) + -4 + *(int *)(in_ECX + 0xc) * 0x10) = in_EDX;
  }
  return;
}

