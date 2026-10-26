
int FUN_00849ef0(void)

{
  int unaff_ESI;
  uint unaff_EDI;
  
  if (unaff_EDI < (uint)((*(int *)(unaff_ESI + 8) - *(int *)(unaff_ESI + 4)) / 0x38)) {
    return *(int *)(unaff_ESI + 4) + unaff_EDI * 0x38;
  }
  return 0;
}

