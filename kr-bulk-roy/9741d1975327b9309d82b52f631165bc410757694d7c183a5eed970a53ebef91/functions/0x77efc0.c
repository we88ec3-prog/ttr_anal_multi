
void FUN_0077efc0(void)

{
  float *pfVar1;
  float *in_EDX;
  int unaff_ESI;
  
  pfVar1 = (float *)(unaff_ESI + 0x74);
  if ((((in_EDX[3] != *(float *)(unaff_ESI + 0x80)) || (*in_EDX != *pfVar1)) ||
      (in_EDX[1] != *(float *)(unaff_ESI + 0x78))) || (in_EDX[2] != *(float *)(unaff_ESI + 0x7c))) {
    if (pfVar1 != in_EDX) {
      *(float *)(unaff_ESI + 0x80) = in_EDX[3];
      *pfVar1 = *in_EDX;
      *(float *)(unaff_ESI + 0x78) = in_EDX[1];
      *(float *)(unaff_ESI + 0x7c) = in_EDX[2];
    }
    *(undefined4 *)(unaff_ESI + 0xc0) = 0;
  }
  return;
}

