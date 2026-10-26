
void Unwind_009343c4(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xd8) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xd8) = *(uint *)(unaff_EBP + -0xd8) & 0xfffffffe;
    FUN_004fa440();
    return;
  }
  return;
}

