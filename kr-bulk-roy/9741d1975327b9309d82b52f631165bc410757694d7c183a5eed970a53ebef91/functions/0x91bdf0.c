
void Unwind_0091bdf0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x140) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x140) = *(uint *)(unaff_EBP + -0x140) & 0xfffffffe;
    FUN_004fa440();
    return;
  }
  return;
}

