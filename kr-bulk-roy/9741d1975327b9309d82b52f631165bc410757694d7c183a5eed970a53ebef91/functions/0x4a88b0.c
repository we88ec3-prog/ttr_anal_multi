
void FUN_004a88b0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x44) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x44) + 0x24))
              (*(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 0x10),0,in_ECX + 0x6c,1,0,
               0xffffffff);
  }
  return;
}

