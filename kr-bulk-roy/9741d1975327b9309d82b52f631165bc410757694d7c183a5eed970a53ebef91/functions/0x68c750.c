
void FUN_0068c750(int param_1)

{
  int *in_ECX;
  
  FUN_0068c2c0(param_1);
  if ((*(int *)(param_1 + 0x10) == 0x578) &&
     (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x41] + 0x20))) {
    FUN_0068c790(in_ECX);
    (**(code **)(*in_ECX + 0xd4))();
  }
  return;
}

