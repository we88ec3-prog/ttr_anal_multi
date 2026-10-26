
void FUN_00650130(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xac) != 0) {
    FUN_0089120c(*(int *)(in_ECX + 0xac));
    *(undefined4 *)(in_ECX + 0xac) = 0;
  }
  return;
}

