
void Unwind_0090435e(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x168) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x168) = *(uint *)(unaff_EBP + -0x168) & 0xfffffffe;
    FUN_00402c50();
    return;
  }
  return;
}

