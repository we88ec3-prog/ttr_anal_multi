
void FUN_0065b430(int param_1)

{
  uint uVar1;
  int *in_EAX;
  int *in_ECX;
  
  uVar1 = in_ECX[1];
  if ((param_1 < 0) && (uVar1 < (uint)-param_1)) {
    *in_EAX = *in_ECX + (-(uVar1 + param_1) - 1 >> 5) * -4 + -4;
    in_EAX[1] = uVar1 + param_1 & 0x1f;
    return;
  }
  *in_EAX = *in_ECX + (uVar1 + param_1 >> 5) * 4;
  in_EAX[1] = uVar1 + param_1 & 0x1f;
  return;
}

