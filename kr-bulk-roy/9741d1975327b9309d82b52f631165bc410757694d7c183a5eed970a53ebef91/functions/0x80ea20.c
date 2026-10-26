
undefined4 FUN_0080ea20(int *param_1,int param_2)

{
  int *in_ECX;
  
  if (in_ECX[5] == 0) {
    return 0x80004001;
  }
  (**(code **)(*in_ECX + 0x2c))();
  in_ECX[7] = param_2;
  in_ECX[4] = (int)param_1;
  (**(code **)(*param_1 + 8))(param_2);
  (**(code **)(*(int *)in_ECX[5] + 4))(param_1);
  (**(code **)(*(int *)in_ECX[5] + 0xc))();
  (**(code **)(*(int *)in_ECX[5] + 0x10))();
  in_ECX[6] = 1;
  FUN_0080e8d0();
  return 0;
}

