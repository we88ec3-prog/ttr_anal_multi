
void Unwind_00941d05(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x94) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x94) = *(uint *)(unaff_EBP + -0x94) & 0xfffffffd;
    FUN_004fa440();
    return;
  }
  return;
}

