
void FUN_00791100(void)

{
  float *in_ECX;
  float *in_EDX;
  
  if (((*in_EDX != 1.0) || (in_EDX[1] != 1.0)) || (in_EDX[2] != 1.0)) {
    in_ECX[0xc] = (float)((uint)in_ECX[0xc] & 0xfffffffb);
    *in_ECX = *in_EDX * *in_ECX;
    in_ECX[1] = in_ECX[1] * *in_EDX;
    in_ECX[2] = in_ECX[2] * *in_EDX;
    in_ECX[3] = in_EDX[1] * in_ECX[3];
    in_ECX[4] = in_EDX[1] * in_ECX[4];
    in_ECX[5] = in_EDX[1] * in_ECX[5];
    in_ECX[6] = in_EDX[2] * in_ECX[6];
    in_ECX[7] = in_ECX[7] * in_EDX[2];
    in_ECX[8] = in_EDX[2] * in_ECX[8];
  }
  return;
}

