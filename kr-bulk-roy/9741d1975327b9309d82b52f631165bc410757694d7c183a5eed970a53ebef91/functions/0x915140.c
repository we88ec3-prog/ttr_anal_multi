
void Unwind_00915140(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + 0xc) & 1) != 0) {
    *(uint *)(unaff_EBP + 0xc) = *(uint *)(unaff_EBP + 0xc) & 0xfffffffe;
    FUN_00730100();
    return;
  }
  return;
}

