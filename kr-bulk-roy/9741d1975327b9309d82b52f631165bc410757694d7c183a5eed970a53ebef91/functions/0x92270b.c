
void Unwind_0092270b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x304) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x304) = *(uint *)(unaff_EBP + -0x304) & 0xfffffffe;
    FUN_00402c50();
    return;
  }
  return;
}

