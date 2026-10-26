
void Unwind_00941ce6(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x94) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x94) = *(uint *)(unaff_EBP + -0x94) & 0xfffffffe;
    FUN_004fa440();
    return;
  }
  return;
}

