
uint FUN_005deef0(int *param_1)

{
  uint in_EAX;
  uint uVar1;
  
  if ((param_1[1] != 0) && (*param_1 == 100)) {
    in_EAX = (**(code **)(*(int *)param_1[1] + 8))();
    if (in_EAX == 0xf4245) {
      uVar1 = FUN_006a2b40();
      return uVar1;
    }
  }
  return in_EAX & 0xffffff00;
}

