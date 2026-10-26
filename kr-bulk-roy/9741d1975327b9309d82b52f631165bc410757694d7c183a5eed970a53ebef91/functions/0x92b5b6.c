
void Unwind_0092b5b6(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x9c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x9c) = *(uint *)(unaff_EBP + -0x9c) & 0xfffffffe;
    FUN_004fa440();
    return;
  }
  return;
}

