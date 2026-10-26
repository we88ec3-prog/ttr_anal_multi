
undefined4 FUN_007430c0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    FUN_00742ec0();
  }
  *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 1;
  return *(undefined4 *)(in_ECX + 4);
}

