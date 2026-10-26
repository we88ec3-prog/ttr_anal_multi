
void FUN_00864cc0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x18);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0x18) = 0;
  }
  FUN_00862b60(*(undefined4 *)(in_ECX + 4));
  return;
}

