
void Unwind_00916e30(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xdc) & 2) != 0) {
    *(uint *)(unaff_EBP + -0xdc) = *(uint *)(unaff_EBP + -0xdc) & 0xfffffffd;
    FUN_00402c50();
    return;
  }
  return;
}

