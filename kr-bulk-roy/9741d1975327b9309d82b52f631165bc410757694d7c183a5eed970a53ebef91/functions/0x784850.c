
undefined4 FUN_00784850(int param_1)

{
  int in_ECX;
  
  if (param_1 != 0) {
    if (*(int **)(param_1 + 0x54) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x54) + 0x5c))(param_1);
      *(undefined4 *)(param_1 + 0x54) = 0;
      *(undefined4 *)(param_1 + 0x5c) = 0;
    }
    *(int *)(param_1 + 0x54) = in_ECX;
    *(int *)(param_1 + 0x5c) = *(int *)(in_ECX + 0x5c) + 1;
    return 1;
  }
  return 0;
}

