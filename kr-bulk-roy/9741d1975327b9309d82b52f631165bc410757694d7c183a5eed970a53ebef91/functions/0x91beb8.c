
void Unwind_0091beb8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x128) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x128) = *(uint *)(unaff_EBP + -0x128) & 0xfffffffe;
    FUN_004fa440();
    return;
  }
  return;
}

