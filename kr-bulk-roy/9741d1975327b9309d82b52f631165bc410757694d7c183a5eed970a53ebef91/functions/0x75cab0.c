
void FUN_0075cab0(int param_1,int *param_2)

{
  code *pcVar1;
  int *in_ECX;
  
  if (param_1 == 1) {
    *param_2 = in_ECX[0x35];
    in_ECX[0x35] = 2;
  }
  else if (param_1 == 2) {
    *param_2 = in_ECX[0x35];
    pcVar1 = *(code **)(*in_ECX + 0x128);
    in_ECX[0x35] = 1;
    (*pcVar1)();
    return;
  }
  (**(code **)(*in_ECX + 0x128))();
  return;
}

