
float10 FUN_007f9ec0(void)

{
  float fVar1;
  float *in_ECX;
  
  if (*in_ECX <= in_ECX[1]) {
    fVar1 = in_ECX[1];
  }
  else {
    fVar1 = *in_ECX;
  }
  if (in_ECX[3] < in_ECX[2]) {
    return (float10)(in_ECX[2] + fVar1);
  }
  return (float10)(in_ECX[3] + fVar1);
}

