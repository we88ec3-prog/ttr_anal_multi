
void Unwind_00912050(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x2038) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x2038) = *(uint *)(unaff_EBP + -0x2038) & 0xfffffffe;
    FUN_00721520();
    return;
  }
  return;
}

