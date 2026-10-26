
void Unwind_00921b9b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x6c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x6c) = *(uint *)(unaff_EBP + -0x6c) & 0xfffffffe;
    FUN_004fa440();
    return;
  }
  return;
}

