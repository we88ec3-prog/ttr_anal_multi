
void Unwind_009343e3(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xd8) & 2) != 0) {
    *(uint *)(unaff_EBP + -0xd8) = *(uint *)(unaff_EBP + -0xd8) & 0xfffffffd;
    FUN_004fa440();
    return;
  }
  return;
}

