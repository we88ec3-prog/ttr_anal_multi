
void FUN_008e1e40(int param_1)

{
  int *piVar1;
  int in_EDX;
  
  piVar1 = (int *)(in_EDX + 0x188);
  if (*(int **)(in_EDX + 0x188) == piVar1) {
    FUN_008e0760();
    return;
  }
  **(int **)(in_EDX + 0x188) = param_1;
  *(undefined4 *)(*piVar1 + 4) = 2;
  *piVar1 = *piVar1 + 8;
  return;
}

