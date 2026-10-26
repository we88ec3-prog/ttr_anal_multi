
int FUN_00519640(void)

{
  int in_ECX;
  int unaff_ESI;
  
  FUN_00519680(&stack0x00000004);
  if (in_ECX != *(int *)(unaff_ESI + 4)) {
    return in_ECX + 0x10;
  }
  return 0;
}

