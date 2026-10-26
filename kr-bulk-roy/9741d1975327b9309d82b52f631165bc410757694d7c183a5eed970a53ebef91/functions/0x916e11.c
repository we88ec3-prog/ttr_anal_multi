
void Unwind_00916e11(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xdc) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xdc) = *(uint *)(unaff_EBP + -0xdc) & 0xfffffffe;
    FUN_007cf450();
    return;
  }
  return;
}

