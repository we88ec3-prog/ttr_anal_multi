
void FUN_00520540(undefined4 *param_1)

{
  undefined4 *in_ECX;
  undefined4 *in_EDX;
  
  for (; in_ECX != in_EDX; in_ECX = in_ECX + 2) {
    *param_1 = *in_ECX;
    param_1[1] = in_ECX[1];
    param_1 = param_1 + 2;
  }
  return;
}

