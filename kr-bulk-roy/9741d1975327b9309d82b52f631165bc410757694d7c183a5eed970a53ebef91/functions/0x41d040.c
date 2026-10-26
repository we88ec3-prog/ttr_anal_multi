
void FUN_0041d040(void)

{
  int in_ECX;
  
  if ((*(uint *)(in_ECX + 0x28) & 0x4000) != 0) {
    *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) ^ 0x4000;
  }
  return;
}

