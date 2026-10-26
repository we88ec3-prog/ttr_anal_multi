
void Unwind_0090d4d0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_004627e0(*(undefined4 *)(unaff_EBP + 0xc));
  }
  return;
}

