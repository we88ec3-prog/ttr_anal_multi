
void Unwind_00938b92(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x7c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x7c) = *(uint *)(unaff_EBP + -0x7c) & 0xfffffffe;
    FUN_007a1050();
    return;
  }
  return;
}

