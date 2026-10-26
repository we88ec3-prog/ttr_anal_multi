
void FUN_00718140(void)

{
  int in_ECX;
  
  if (*(int **)(in_ECX + 0xc) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0xc) + 4))();
  }
  *(undefined4 *)(in_ECX + 0xc) = 0;
  return;
}

