
void Unwind_009406ce(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x454) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x454) = *(uint *)(unaff_EBP + -0x454) & 0xfffffffe;
    FUN_004fa440();
    return;
  }
  return;
}

