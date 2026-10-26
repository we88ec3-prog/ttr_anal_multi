
void Unwind_00921300(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14c) = *(uint *)(unaff_EBP + -0x14c) & 0xfffffffe;
    FUN_004fa440();
    return;
  }
  return;
}

