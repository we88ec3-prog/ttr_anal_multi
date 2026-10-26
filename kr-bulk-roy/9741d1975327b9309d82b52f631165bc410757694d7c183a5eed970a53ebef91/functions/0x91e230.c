
void Unwind_0091e230(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x88) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x88) = *(uint *)(unaff_EBP + -0x88) & 0xfffffffe;
    FUN_004fa440();
    return;
  }
  return;
}

