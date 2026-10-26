
void Unwind_00945581(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xf4) & 8) != 0) {
    *(uint *)(unaff_EBP + -0xf4) = *(uint *)(unaff_EBP + -0xf4) & 0xfffffff7;
    FUN_004fa440();
    return;
  }
  return;
}

