
void FUN_0082ce80(void)

{
  float *in_ECX;
  int in_EDX;
  
  if (0.0 <= *in_ECX) {
    if (*(float *)(in_EDX + 0xc) < *in_ECX != (*(float *)(in_EDX + 0xc) == *in_ECX)) {
      *in_ECX = *(float *)(in_EDX + 0xc) - 1.0;
    }
  }
  else {
    *in_ECX = 0.0;
  }
  if (0.0 <= in_ECX[1]) {
    if (*(float *)(in_EDX + 0x10) < in_ECX[1] == (*(float *)(in_EDX + 0x10) == in_ECX[1])) {
      return;
    }
    in_ECX[1] = *(float *)(in_EDX + 0x10) - 1.0;
    return;
  }
  in_ECX[1] = 0.0;
  return;
}

