
void FUN_00855350(void)

{
  float *in_ECX;
  int in_EDX;
  
  if (0.0 < *in_ECX) {
    if (1.0 <= *in_ECX) {
      *(undefined4 *)(in_EDX + 0x1cc) = 0x3f800000;
      return;
    }
    if (0.0 < *in_ECX) {
      *(float *)(in_EDX + 0x1cc) = *in_ECX;
      return;
    }
  }
  *(undefined4 *)(in_EDX + 0x1cc) = 0;
  return;
}

