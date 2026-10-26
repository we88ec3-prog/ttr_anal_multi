
void FUN_00648100(void)

{
  char in_AL;
  int in_ECX;
  
  *(char *)(in_ECX + 0xb0) = in_AL;
  if (in_AL != '\0') {
    *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) | 4;
    (**(code **)(**(int **)(in_ECX + 0xac) + 0x94))(1);
    (**(code **)(**(int **)(in_ECX + 0xa8) + 0x94))(0);
    return;
  }
  if ((*(uint *)(in_ECX + 0x28) & 4) != 0) {
    *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) ^ 4;
  }
  (**(code **)(**(int **)(in_ECX + 0xac) + 0x94))(0);
  (**(code **)(**(int **)(in_ECX + 0xa8) + 0x94))(1);
  FUN_006481d0();
  return;
}

