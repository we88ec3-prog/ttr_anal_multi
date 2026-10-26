
void FUN_00413910(void)

{
  int in_ECX;
  
  if ((*(uint *)(*(int *)(in_ECX + 0x80) + 0x28) >> 8 & 1) != 0) {
    FUN_0069bb20();
  }
  return;
}

