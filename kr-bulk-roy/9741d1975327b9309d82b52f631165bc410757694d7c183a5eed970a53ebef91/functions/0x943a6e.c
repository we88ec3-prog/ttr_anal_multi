
void Unwind_00943a6e(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xfc) & 8) != 0) {
    *(uint *)(unaff_EBP + -0xfc) = *(uint *)(unaff_EBP + -0xfc) & 0xfffffff7;
    FUN_004fa440();
    return;
  }
  return;
}

