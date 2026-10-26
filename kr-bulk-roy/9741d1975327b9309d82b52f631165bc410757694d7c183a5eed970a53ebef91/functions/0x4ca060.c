
undefined4 FUN_004ca060(int param_1)

{
  int *piVar1;
  int in_ECX;
  
  if ((param_1 != 0x1a) && (*(int *)(in_ECX + 4 + param_1 * 4) != 0)) {
    (**(code **)(**(int **)(in_ECX + 0x68) + 0xc))();
    *(undefined4 *)(*(int *)(in_ECX + 4 + param_1 * 4) + 0xc) =
         *(undefined4 *)(*(int *)(in_ECX + 0x68) + 8);
    piVar1 = *(int **)(in_ECX + 4 + param_1 * 4);
    *(int **)(in_ECX + 0x68) = piVar1;
    (**(code **)(*piVar1 + 4))();
    return 1;
  }
  return 0;
}

