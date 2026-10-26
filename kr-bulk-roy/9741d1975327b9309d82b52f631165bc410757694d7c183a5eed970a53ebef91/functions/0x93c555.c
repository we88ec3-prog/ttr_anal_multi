
void Unwind_0093c555(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x74) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x74) = *(uint *)(unaff_EBP + -0x74) & 0xfffffffd;
    FUN_004fa440();
    return;
  }
  return;
}

