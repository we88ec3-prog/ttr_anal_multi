
void FUN_00746ad0(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x3c) != 0) && ((*(uint *)(in_ECX + 0x28) & 0x40000) == 0)) {
    FUN_00746c10();
    return;
  }
  return;
}

