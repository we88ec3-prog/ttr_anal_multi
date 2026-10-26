
void Unwind_009439f0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xfc) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xfc) = *(uint *)(unaff_EBP + -0xfc) & 0xfffffffe;
    FUN_004fa440();
    return;
  }
  return;
}

