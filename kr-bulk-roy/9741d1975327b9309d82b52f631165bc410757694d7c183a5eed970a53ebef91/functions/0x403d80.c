
void FUN_00403d80(char param_1)

{
  int in_ECX;
  
  if (param_1 != '\0') {
    *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) | 0x4000;
    return;
  }
  if ((*(uint *)(in_ECX + 0x28) & 0x4000) != 0) {
    *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) ^ 0x4000;
  }
  return;
}

