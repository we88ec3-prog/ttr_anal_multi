
void Unwind_009043cf(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x168) & 8) != 0) {
    *(uint *)(unaff_EBP + -0x168) = *(uint *)(unaff_EBP + -0x168) & 0xfffffff7;
    FUN_00402c50();
    return;
  }
  return;
}

