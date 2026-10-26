
undefined4 FUN_005e0d20(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  if ((param_1[1] != 0) && (*param_1 == 100)) {
    iVar1 = (**(code **)(*(int *)param_1[1] + 8))();
    if ((iVar1 == 0xf4245) &&
       ((*(int *)(param_1[1] + 0x25c) != 0 &&
        (*(int *)(*(int *)(param_1[1] + 0x25c) + 8) - 1U < 0x2b)))) {
      iVar1 = FUN_00520f40();
      if ((0 < iVar1) && ((0 < *(int *)(in_ECX + 0x29c) && (*(int *)(in_ECX + 0x29c) == iVar1)))) {
        return 1;
      }
    }
  }
  return 0;
}

