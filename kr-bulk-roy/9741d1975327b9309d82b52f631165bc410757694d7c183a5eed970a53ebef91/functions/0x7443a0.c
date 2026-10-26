
void FUN_007443a0(void)

{
  int *piVar1;
  int in_ECX;
  
  FUN_00745530();
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
  FUN_00744370();
  return;
}

