
void FUN_0075fab0(int param_1,int *param_2)

{
  int *in_ECX;
  
  if ((0 < param_1) && (param_1 < 3)) {
    *param_2 = in_ECX[0x35];
    in_ECX[0x35] = 1;
  }
  (**(code **)(*in_ECX + 0x128))();
  return;
}

