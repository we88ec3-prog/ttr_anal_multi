
void FUN_008ff450(void)

{
  ushort in_FPUControlWord;
  float10 in_ST0;
  
  if ((DAT_00fe728c != 0) && ((MXCSR & 0x7f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    FUN_009017e0();
    return;
  }
  FUN_00900d28((double)in_ST0);
  FUN_008ff4a8();
  return;
}

