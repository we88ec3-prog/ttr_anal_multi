
void Unwind_0094555f(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xf4) & 4) != 0) {
    *(uint *)(unaff_EBP + -0xf4) = *(uint *)(unaff_EBP + -0xf4) & 0xfffffffb;
    FUN_004fa440();
    return;
  }
  return;
}

