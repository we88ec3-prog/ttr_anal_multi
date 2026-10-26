
void FUN_008fd7d0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00571e40();
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  if (*(int *)(in_ECX + 8) != 0) {
    FUN_0089120c(*(int *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 8) = 0;
  }
  return;
}

