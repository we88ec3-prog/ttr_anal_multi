
undefined4 FUN_005dddc0(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  if ((*(char *)(in_ECX + 0x2a1) != '\0') || (*(char *)(in_ECX + 0x2cc) != '\0')) {
    return 0;
  }
  if (((param_1[1] == 0) ||
      (((*param_1 != 100 || (iVar2 = (**(code **)(*(int *)param_1[1] + 8))(), iVar2 != 0xf4245)) &&
       ((param_1[1] == 0 ||
        ((*param_1 != 100 || (iVar2 = (**(code **)(*(int *)param_1[1] + 8))(), iVar2 != 0xf4246)))))
       ))) && (cVar1 = FUN_00755c10(0xf424b), cVar1 == '\0')) {
    return 0;
  }
  if (param_1[1] == in_ECX) {
    return 0;
  }
  return 1;
}

