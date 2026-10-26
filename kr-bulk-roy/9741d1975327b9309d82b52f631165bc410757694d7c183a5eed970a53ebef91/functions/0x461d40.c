
uint FUN_00461d40(int *param_1)

{
  if ((param_1[1] != 0) && (*param_1 == 100)) {
    param_1 = (int *)(**(code **)(*(int *)param_1[1] + 8))();
  }
  return (uint)param_1 & 0xffffff00;
}

