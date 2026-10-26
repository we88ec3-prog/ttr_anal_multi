
uint FUN_005fa9f0(int *param_1)

{
  if ((param_1[1] != 0) && (*param_1 == 100)) {
    param_1 = (int *)(**(code **)(*(int *)param_1[1] + 8))();
    if (param_1 == (int *)0xf4245) {
      return 0xf4201;
    }
  }
  return (uint)param_1 & 0xffffff00;
}

