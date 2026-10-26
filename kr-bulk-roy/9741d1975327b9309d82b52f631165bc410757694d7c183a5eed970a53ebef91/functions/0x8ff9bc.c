
void FUN_008ff9bc(void)

{
  ushort in_FPUControlWord;
  
  if ((DAT_00fe728c != 0) && ((MXCSR & 0x7f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    FUN_00902950();
    return;
  }
  __cintrindisp1();
  return;
}

