
uint FUN_008be800(int param_1,int param_2)

{
  if (*(int *)(param_1 + 4) < *(int *)(param_2 + 4)) {
    return 0xffffffff;
  }
  return (uint)(*(int *)(param_2 + 4) < *(int *)(param_1 + 4));
}

