
void Unwind_00943adb(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xfc) & 0x20) != 0) {
    *(uint *)(unaff_EBP + -0xfc) = *(uint *)(unaff_EBP + -0xfc) & 0xffffffdf;
    FUN_004fa440();
    return;
  }
  return;
}

