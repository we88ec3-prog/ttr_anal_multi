
void FUN_007654a0(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x24) != 0) && ((*(uint *)(in_ECX + 0x28) >> 0x11 & 1) == 0)) {
    FUN_00443d10();
    *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) | 0x20000;
  }
  return;
}

