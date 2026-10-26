
void Unwind_009322f7(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x74) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x74) = *(uint *)(unaff_EBP + -0x74) & 0xfffffffd;
    FUN_00402c50();
    return;
  }
  return;
}

