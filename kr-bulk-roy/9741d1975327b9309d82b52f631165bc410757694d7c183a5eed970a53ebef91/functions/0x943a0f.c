
void Unwind_00943a0f(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xfc) & 2) != 0) {
    *(uint *)(unaff_EBP + -0xfc) = *(uint *)(unaff_EBP + -0xfc) & 0xfffffffd;
    FUN_004fa440();
    return;
  }
  return;
}

