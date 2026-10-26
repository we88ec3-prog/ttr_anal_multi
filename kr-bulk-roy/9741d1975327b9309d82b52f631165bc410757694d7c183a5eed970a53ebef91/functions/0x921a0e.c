
void Unwind_00921a0e(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xe8) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xe8) = *(uint *)(unaff_EBP + -0xe8) & 0xfffffffe;
    FUN_004fa440();
    return;
  }
  return;
}

