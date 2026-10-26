
void FUN_006d5ee0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x34) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x34) + 0x78))
              (*(int **)(in_ECX + 0x34),*(undefined4 *)(in_ECX + 0x50),
               *(undefined4 *)(in_ECX + 0x7c));
  }
  return;
}

