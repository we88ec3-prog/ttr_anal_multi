
void FUN_008ff5a0(void)

{
  ushort in_FPUControlWord;
  float10 in_ST0;
  float10 in_ST1;
  
  if ((DAT_00fe728c != 0) && ((MXCSR & 0x7f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    FUN_00901c50();
    return;
  }
  FUN_008ff5fd((double)in_ST1,(double)in_ST0);
  return;
}

