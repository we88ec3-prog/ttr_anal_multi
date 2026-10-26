
void Unwind_00919e78(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x130) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x130) = *(uint *)(unaff_EBP + -0x130) & 0xfffffffe;
    FUN_004fa440();
    return;
  }
  return;
}

