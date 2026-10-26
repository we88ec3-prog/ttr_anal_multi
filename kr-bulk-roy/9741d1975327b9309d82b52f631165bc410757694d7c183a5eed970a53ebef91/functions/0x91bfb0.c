
void Unwind_0091bfb0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x144) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x144) = *(uint *)(unaff_EBP + -0x144) & 0xfffffffe;
    FUN_004fa440();
    return;
  }
  return;
}

