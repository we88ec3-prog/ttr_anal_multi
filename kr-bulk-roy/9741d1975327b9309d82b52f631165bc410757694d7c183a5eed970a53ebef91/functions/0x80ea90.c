
int FUN_0080ea90(int *param_1,int param_2)

{
  int iVar1;
  int *in_ECX;
  
  if (in_ECX[5] == 0) {
    return -0x7fffbfff;
  }
  (**(code **)(*in_ECX + 0x2c))();
  in_ECX[7] = param_2;
  in_ECX[4] = (int)param_1;
  (**(code **)(*param_1 + 8))(param_2);
  (**(code **)(*(int *)in_ECX[5] + 4))(param_1);
  iVar1 = (**(code **)(*(int *)in_ECX[5] + 0xc))();
  return (-(uint)(iVar1 != 0) & 0x7fffbffb) + 0x80004005;
}

