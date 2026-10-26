
void FUN_00854fd0(void)

{
  float *in_ECX;
  int in_EDX;
  
  if (0.0 < *in_ECX) {
    if (1.0 <= *in_ECX) {
      *(undefined4 *)(in_EDX + 0x1c8) = 0x3f800000;
      return;
    }
    if (0.0 < *in_ECX) {
      *(float *)(in_EDX + 0x1c8) = *in_ECX;
      return;
    }
  }
  *(undefined4 *)(in_EDX + 0x1c8) = 0;
  return;
}

