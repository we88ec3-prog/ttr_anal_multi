
void Unwind_0092b5d5(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x9c) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x9c) = *(uint *)(unaff_EBP + -0x9c) & 0xfffffffd;
    FUN_004fa440();
    return;
  }
  return;
}

