
void Unwind_00903c41(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x168) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x168) = *(uint *)(unaff_EBP + -0x168) & 0xfffffffe;
    FUN_004fa440();
    return;
  }
  return;
}

