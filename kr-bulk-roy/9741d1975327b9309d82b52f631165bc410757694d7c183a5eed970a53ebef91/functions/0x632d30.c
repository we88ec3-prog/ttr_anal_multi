
undefined4 FUN_00632d30(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xf4) != 0) {
    cVar1 = (**(code **)(**(int **)(in_ECX + 0xf4) + 0xec))(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}

