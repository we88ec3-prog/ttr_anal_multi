
void Unwind_00904380(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x168) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x168) = *(uint *)(unaff_EBP + -0x168) & 0xfffffffd;
    FUN_00402c50();
    return;
  }
  return;
}

