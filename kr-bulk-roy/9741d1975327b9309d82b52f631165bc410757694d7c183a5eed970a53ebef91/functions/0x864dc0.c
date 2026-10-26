
void FUN_00864dc0(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x1c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0x1c) = 0;
  }
  FUN_00862aa0(*(undefined4 *)(in_ECX + 4),param_1,(undefined4 *)(in_ECX + 0x1c));
  return;
}

