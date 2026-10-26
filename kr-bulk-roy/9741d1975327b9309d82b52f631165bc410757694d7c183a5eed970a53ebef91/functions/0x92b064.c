
void Unwind_0092b064(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xc4) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xc4) = *(uint *)(unaff_EBP + -0xc4) & 0xfffffffe;
    FUN_00757640(*(undefined4 *)(unaff_EBP + -200));
  }
  return;
}

