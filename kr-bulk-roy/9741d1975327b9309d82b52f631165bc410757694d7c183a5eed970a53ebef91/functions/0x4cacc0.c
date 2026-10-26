
void FUN_004cacc0(float *param_1,int param_2)

{
  code *pcVar1;
  int *in_ECX;
  
  if (((*param_1 != (float)in_ECX[0x28]) || (param_1[1] != (float)in_ECX[0x29])) ||
     (param_1[2] != (float)in_ECX[0x2a])) {
    in_ECX[0x28] = (int)*param_1;
    in_ECX[0x29] = (int)param_1[1];
    in_ECX[0x2a] = (int)param_1[2];
    in_ECX[0x2b] = param_2;
    if (param_2 != 0) {
      pcVar1 = *(code **)(*in_ECX + 0x38);
      in_ECX[0x2b] = 1;
      (*pcVar1)();
    }
  }
  return;
}

