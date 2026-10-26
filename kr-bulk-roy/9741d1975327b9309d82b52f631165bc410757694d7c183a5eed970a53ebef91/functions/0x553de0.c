
void FUN_00553de0(void)

{
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x44) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x44) + 8))();
    *(undefined4 *)(in_ECX + 0x44) = 0;
  }
  return;
}

