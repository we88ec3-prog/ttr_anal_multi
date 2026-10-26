
void FUN_0076d290(int param_1,int *param_2)

{
  code *pcVar1;
  int *in_ECX;
  
  if (param_1 == 1) {
    *param_2 = in_ECX[0x33];
    in_ECX[0x33] = 2;
  }
  else if (param_1 == 2) {
    *param_2 = in_ECX[0x33];
    pcVar1 = *(code **)(*in_ECX + 0x128);
    in_ECX[0x33] = 1;
    (*pcVar1)();
    return;
  }
  (**(code **)(*in_ECX + 0x128))();
  return;
}

