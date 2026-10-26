
void FUN_00553c70(int param_1,int param_2)

{
  int *in_ECX;
  
  in_ECX[1] = param_1;
  in_ECX[2] = param_2;
  (**(code **)(*in_ECX + 0x1c))();
  return;
}

