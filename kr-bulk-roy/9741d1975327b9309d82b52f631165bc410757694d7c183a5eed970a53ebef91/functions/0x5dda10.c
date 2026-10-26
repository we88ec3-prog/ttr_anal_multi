
undefined4 FUN_005dda10(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x2a1) != '\0') {
    return 0;
  }
  if (param_1[1] == 0) {
    return 0;
  }
  if ((*param_1 != 100) || (iVar1 = (**(code **)(*(int *)param_1[1] + 8))(), iVar1 != 0xf4245)) {
    if (param_1[1] == 0) {
      return 0;
    }
    if (*param_1 != 100) {
      return 0;
    }
    iVar1 = (**(code **)(*(int *)param_1[1] + 8))();
    if (iVar1 != 0xf4246) {
      return 0;
    }
  }
  if (param_1[1] == in_ECX) {
    return 0;
  }
  return 1;
}

