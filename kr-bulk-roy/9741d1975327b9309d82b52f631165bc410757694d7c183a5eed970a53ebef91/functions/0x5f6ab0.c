
undefined4 FUN_005f6ab0(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  if (param_1[1] != 0) {
    if ((*param_1 == 100) && (iVar1 = (**(code **)(*(int *)param_1[1] + 8))(), iVar1 == 0xf4246)) {
      if (*(int *)(in_ECX + 0x20) + 1 != *(int *)(param_1[1] + 0x2d0)) {
        return 1;
      }
      return 0;
    }
    if (((param_1[1] != 0) && (*param_1 == 100)) &&
       (iVar1 = (**(code **)(*(int *)param_1[1] + 8))(), iVar1 == 0xf4245)) {
      return 1;
    }
  }
  return 0;
}

