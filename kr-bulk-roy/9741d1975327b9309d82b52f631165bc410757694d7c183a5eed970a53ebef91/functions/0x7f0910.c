
bool FUN_007f0910(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x38) < 1) {
    FUN_007f0500();
  }
  return *(int *)(in_ECX + 0x128) == 0;
}

