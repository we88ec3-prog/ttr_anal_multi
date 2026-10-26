
void Unwind_0091e450(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -200) & 1) != 0) {
    *(uint *)(unaff_EBP + -200) = *(uint *)(unaff_EBP + -200) & 0xfffffffe;
    FUN_00402c50();
    return;
  }
  return;
}

