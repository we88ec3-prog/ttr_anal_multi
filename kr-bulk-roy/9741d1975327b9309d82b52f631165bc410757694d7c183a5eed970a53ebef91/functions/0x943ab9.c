
void Unwind_00943ab9(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xfc) & 0x10) != 0) {
    *(uint *)(unaff_EBP + -0xfc) = *(uint *)(unaff_EBP + -0xfc) & 0xffffffef;
    FUN_004fa440();
    return;
  }
  return;
}

