
int FUN_008c73f0(int *param_1,int *param_2)

{
  if (*(uint *)(*param_2 + 4) < *(uint *)(*param_1 + 4)) {
    return 1;
  }
  return -(uint)(*(uint *)(*param_1 + 4) < *(uint *)(*param_2 + 4));
}

