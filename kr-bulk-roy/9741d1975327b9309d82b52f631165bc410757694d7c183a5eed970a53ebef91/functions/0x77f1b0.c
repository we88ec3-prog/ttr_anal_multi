
undefined4 FUN_0077f1b0(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  if (param_1 != (int *)0x0) {
    if ((int *)param_1[0x15] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0x15] + 0x5c))(param_1);
      param_1[0x15] = 0;
      param_1[0x17] = 0;
    }
    param_1[0x15] = in_ECX;
    param_1[0x17] = *(int *)(in_ECX + 0x5c) + 1;
    iVar1 = (**(code **)(*param_1 + 4))();
    if (*(int *)(iVar1 + 4) == -0x5eed0000) {
      param_1[0x30] = 0;
    }
    FUN_0077f890();
    return 1;
  }
  return 0;
}

