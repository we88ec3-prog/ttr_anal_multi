
void Unwind_00921a3e(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xe8) & 2) != 0) {
    *(uint *)(unaff_EBP + -0xe8) = *(uint *)(unaff_EBP + -0xe8) & 0xfffffffd;
    FUN_004fa440();
    return;
  }
  return;
}

