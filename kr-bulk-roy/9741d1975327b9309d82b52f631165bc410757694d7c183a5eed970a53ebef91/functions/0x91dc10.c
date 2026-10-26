
void Unwind_0091dc10(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xc0) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xc0) = *(uint *)(unaff_EBP + -0xc0) & 0xfffffffe;
    FUN_00402c50();
    return;
  }
  return;
}

