
void FUN_007445d0(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if ((iVar1 == 0xcb) || (iVar1 == 0xcc)) {
    if ((*(int **)(in_ECX + 0x98) != (int *)0x0) && ((*(uint *)(in_ECX + 0x28) >> 10 & 1) == 0)) {
      (**(code **)(**(int **)(in_ECX + 0x98) + 0x44))(0);
    }
  }
  else if (((iVar1 == 100) && (*(int **)(in_ECX + 0x9c) != (int *)0x0)) &&
          ((*(uint *)(in_ECX + 0x28) >> 9 & 1) == 0)) {
    (**(code **)(**(int **)(in_ECX + 0x9c) + 0x44))(0);
    return;
  }
  return;
}

