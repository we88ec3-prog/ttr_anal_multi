
void Unwind_0092290b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xec) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xec) = *(uint *)(unaff_EBP + -0xec) & 0xfffffffe;
    FUN_00402c50();
    return;
  }
  return;
}

