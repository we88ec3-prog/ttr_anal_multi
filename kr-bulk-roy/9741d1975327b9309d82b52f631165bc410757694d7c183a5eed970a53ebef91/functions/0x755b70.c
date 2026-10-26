
void FUN_00755b70(void)

{
  int *piVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x3c) != 0) && ((*(uint *)(in_ECX + 0x28) & 0x40000) == 0)) {
    FUN_00746c10();
  }
  piVar1 = *(int **)(in_ECX + 0x84);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0x84) = 0;
  }
  piVar1 = *(int **)(in_ECX + 0x88);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0x88) = 0;
  }
  return;
}

