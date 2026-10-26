
void Unwind_00940f62(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x74) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x74) = *(uint *)(unaff_EBP + -0x74) & 0xfffffffe;
    FUN_007a1050();
    return;
  }
  return;
}

