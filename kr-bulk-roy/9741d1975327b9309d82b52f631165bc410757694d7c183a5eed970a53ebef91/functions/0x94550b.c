
void Unwind_0094550b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xf4) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xf4) = *(uint *)(unaff_EBP + -0xf4) & 0xfffffffe;
    FUN_004fa440();
    return;
  }
  return;
}

