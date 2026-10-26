
void Unwind_00921bbf(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x6c) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x6c) = *(uint *)(unaff_EBP + -0x6c) & 0xfffffffd;
    FUN_004fa440();
    return;
  }
  return;
}

