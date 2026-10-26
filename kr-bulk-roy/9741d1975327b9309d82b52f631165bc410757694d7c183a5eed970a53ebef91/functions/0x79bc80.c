
undefined4 FUN_0079bc80(void)

{
  int in_EAX;
  float *in_ECX;
  
  if (0.0 < *(float *)(in_EAX + 0x2f4) * in_ECX[2] +
            *(float *)(in_EAX + 0x2ec) * *in_ECX + *(float *)(in_EAX + 0x2f0) * in_ECX[1] +
            *(float *)(in_EAX + 0x2f8)) {
    return 1;
  }
  return 0;
}

