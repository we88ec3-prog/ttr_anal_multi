
void FUN_008ff1d0(void)

{
  ushort in_FPUControlWord;
  float10 in_ST0;
  
  if ((DAT_00fe728c != 0) && ((MXCSR & 0x7f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    FUN_009011b0();
    return;
  }
  FUN_00900d28((double)in_ST0);
  FUN_008ff228();
  return;
}

