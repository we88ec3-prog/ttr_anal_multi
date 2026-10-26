
void Unwind_0091c000(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x148) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x148) = *(uint *)(unaff_EBP + -0x148) & 0xfffffffe;
    FUN_004fa440();
    return;
  }
  return;
}

