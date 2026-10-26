
void FUN_004d7de0(int *param_1)

{
  int *in_ECX;
  
  if (7 < (uint)in_ECX[5]) {
    *param_1 = *in_ECX + in_ECX[4] * 2;
    return;
  }
  *param_1 = (int)in_ECX + in_ECX[4] * 2;
  return;
}

