
void Unwind_0091b878(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -300) & 1) != 0) {
    *(uint *)(unaff_EBP + -300) = *(uint *)(unaff_EBP + -300) & 0xfffffffe;
    FUN_004fa440();
    return;
  }
  return;
}

