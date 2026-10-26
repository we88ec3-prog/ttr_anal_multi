
undefined4 FUN_0081a820(char param_1)

{
  uint uVar1;
  int in_EDX;
  
  uVar1 = 0;
  if (*(int *)(in_EDX + 8) != *(int *)(in_EDX + 4)) {
    do {
      if (*(char *)(*(int *)(in_EDX + 4) + uVar1) == param_1) {
        return 1;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < (uint)(*(int *)(in_EDX + 8) - *(int *)(in_EDX + 4)));
  }
  return 0;
}

